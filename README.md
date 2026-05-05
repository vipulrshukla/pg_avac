# pg_avac

**Automatic vacuum manager for PostgreSQL** — like a Roomba for your database.

`pg_avac` is a PostgreSQL extension that runs as a background worker, continuously monitoring table statistics and firing vacuum jobs intelligently — only when a table actually needs it. It also watches for long-running prepared transactions that can block XID cleanup, and suggests storage parameter changes for tables under heavy load.

---

## How it works

pg_avac wakes on a configurable interval and evaluates every table in your database against three signals:

| Signal | What it measures |
|---|---|
| **Dead tuple ratio** | `n_dead_tup / (n_live_tup + n_dead_tup)` — primary trigger |
| **DML rate** | Inserts + updates + deletes per second since last cycle |
| **Vacuum age** | Seconds since the table was last vacuumed |

From these it assigns each table a strategy: do nothing, `ANALYZE` only, `VACUUM`, `VACUUM ANALYZE`, or flag for manual `VACUUM FULL`. It also separately watches `pg_prepared_xacts` for prepared transactions older than a threshold and fires alerts before they cause bloat.

```
PostgreSQL
└── pg_avac background worker
    ├── Monitor loop  (wakes every N seconds)
    │   ├── Dead tuple ratio check
    │   ├── DML rate check
    │   └── Vacuum age check
    ├── Decision engine  (scores + picks strategy)
    ├── Job executor  (runs VACUUM / ANALYZE)
    ├── Notifier  (pg_notify + log table)
    ├── Prepared TX watcher  (alerts on old XIDs)
    └── Config advisor  (suggests ALTER TABLE params)
```

---

## Requirements

- PostgreSQL 14 or later
- GCC or Clang
- `pg_config` in your `PATH`
- Superuser access to install

---

## Installation

### 1. Clone the repository

```bash
git clone https://github.com/vipulrshukla/pg_avac.git
cd pg_avac
```

### 2. Build and install

```bash
make
sudo make install
```

This uses PostgreSQL's PGXS build system. It will automatically find your PostgreSQL installation via `pg_config`. If you have multiple PostgreSQL versions installed, specify which one:

```bash
make PG_CONFIG=/usr/lib/postgresql/16/bin/pg_config
sudo make PG_CONFIG=/usr/lib/postgresql/16/bin/pg_config install
```

### 3. Add to `postgresql.conf`

pg_avac runs as a background worker, so it must be loaded at server start:

```ini
# postgresql.conf
shared_preload_libraries = 'pg_avac'
```

If you already have other libraries in `shared_preload_libraries`, append it:

```ini
shared_preload_libraries = 'pg_stat_statements, pg_avac'
```

### 4. Restart PostgreSQL

```bash
# systemd
sudo systemctl restart postgresql

# or for a specific version
sudo systemctl restart postgresql@16-main
```

### 5. Create the extension in your database

```sql
CREATE EXTENSION pg_avac;
```

That's it. The background worker starts automatically.

---

## Configuration

All settings can be changed in `postgresql.conf` or with `ALTER SYSTEM` — no restart needed for most parameters (they take effect on the next wake cycle).

| Parameter | Default | Description |
|---|---|---|
| `pg_avac.naptime` | `60` | Seconds between monitor cycles |
| `pg_avac.dead_ratio` | `0.05` | Dead tuple ratio that triggers vacuum (0.05 = 5%) |
| `pg_avac.min_dead_tuples` | `1000` | Minimum dead rows before a table is considered |
| `pg_avac.dml_rate_threshold` | `100` | DML rows/sec that marks a table as high-churn |
| `pg_avac.max_vacuum_age` | `3600` | Seconds since last vacuum before forcing one |
| `pg_avac.prepared_tx_max_age` | `1800` | Seconds before a prepared transaction triggers an alert |
| `pg_avac.databases` | *(current db)* | Comma-separated list of databases to monitor |
| `pg_avac.dry_run` | `false` | Log decisions without executing any vacuum commands |

### Example: tuning for a busy OLTP database

```ini
pg_avac.naptime = 30
pg_avac.dead_ratio = 0.02
pg_avac.min_dead_tuples = 500
pg_avac.dml_rate_threshold = 500
pg_avac.prepared_tx_max_age = 300
```

### Apply without restart

```sql
ALTER SYSTEM SET pg_avac.dead_ratio = 0.02;
SELECT pg_reload_conf();
```

---

## Usage

### Check what pg_avac is doing

```sql
-- Recent vacuum decisions
SELECT table_name, strategy, dead_ratio, dml_rate, executed_at
FROM pg_avac.vacuum_log
ORDER BY executed_at DESC
LIMIT 20;

-- Tables currently flagged for attention
SELECT * FROM pg_avac.flagged_tables;

-- Alert history (prepared transactions, VACUUM FULL candidates)
SELECT severity, message, created_at
FROM pg_avac.alert_log
ORDER BY created_at DESC;
```

### Listen for real-time notifications

From any `psql` session or application:

```sql
LISTEN pg_avac_events;   -- vacuum job started/completed
LISTEN pg_avac_alerts;   -- prepared TX warnings, VACUUM FULL recommendations
```

Notifications arrive as JSON:

```json
{
  "event": "vacuum_complete",
  "table": "public.orders",
  "strategy": "VACUUM_ANALYZE",
  "dead_ratio_before": 0.12,
  "duration_ms": 843
}
```

```json
{
  "event": "prepared_tx_alert",
  "severity": "CRITICAL",
  "gid": "txn_order_42",
  "age_seconds": 7200,
  "owner": "app_user",
  "message": "Prepared transaction is blocking XID horizon cleanup"
}
```

### Config advisor

For tables that pg_avac keeps flagging but can't clean fast enough, query the advisor:

```sql
SELECT * FROM pg_avac.config_suggestions;
```

Output:

```
 table_name | parameter                        | current | suggested | reason
------------+----------------------------------+---------+-----------+------------------------------------------
 orders     | autovacuum_vacuum_scale_factor   | 0.2     | 0.02      | High DML rate: 842 rows/s, bloat ratio 18%
 events     | autovacuum_vacuum_cost_delay      | 2ms     | 0ms       | Large table with infrequent bulk inserts
```

Apply a suggestion:

```sql
-- Review first, then apply
ALTER TABLE public.orders SET (autovacuum_vacuum_scale_factor = 0.02);
```

Or let pg_avac apply it for you (requires `pg_avac.allow_auto_config = true`):

```sql
SELECT pg_avac.apply_suggestion('public.orders', 'autovacuum_vacuum_scale_factor');
```

### Dry run mode

Test what pg_avac *would* do without touching anything:

```sql
ALTER SYSTEM SET pg_avac.dry_run = true;
SELECT pg_reload_conf();

-- Now watch the log to see what would have been vacuumed
SELECT * FROM pg_avac.vacuum_log ORDER BY executed_at DESC;
```

---

## Monitoring queries

### Tables with the most dead rows right now

```sql
SELECT schemaname, relname, n_dead_tup, n_live_tup,
       round(n_dead_tup::numeric / nullif(n_dead_tup + n_live_tup, 0) * 100, 1) AS dead_pct,
       last_autovacuum, last_vacuum
FROM pg_stat_user_tables
ORDER BY n_dead_tup DESC
LIMIT 10;
```

### Check for long-running prepared transactions manually

```sql
SELECT gid, prepared, now() - prepared AS age,
       transaction AS xid,
       age(transaction) AS xid_age
FROM pg_prepared_xacts
ORDER BY prepared ASC;
```

### pg_avac worker status

```sql
SELECT * FROM pg_avac.worker_status;
```

---

## Uninstall

```sql
DROP EXTENSION pg_avac;
```

Then remove from `postgresql.conf` and restart PostgreSQL.

---

## Contributing

Pull requests are welcome. To run the test suite:

```bash
make installcheck
```

---

## License

PostgreSQL License — same as PostgreSQL itself. See [LICENSE](LICENSE).
