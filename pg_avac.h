#ifndef PG_AVAC_H
#define PG_AVAC_H

#include "postgres.h"
#include "storage/lock.h"

/* ----------------------------------------------------------------
 * Extension identity
 * ---------------------------------------------------------------- */
#define PG_AVAC_VERSION       "1.0"
#define PG_AVAC_NOTIFY_CHANNEL   "pg_avac_events"
#define PG_AVAC_ALERT_CHANNEL    "pg_avac_alerts"

/* ----------------------------------------------------------------
 * GUC parameter names  (set in postgresql.conf or ALTER SYSTEM)
 * ---------------------------------------------------------------- */
#define GUC_NAPTIME          "pg_avac.naptime"           /* seconds between wake cycles          */
#define GUC_DEAD_RATIO       "pg_avac.dead_ratio"        /* dead_tup / live_tup threshold (0-1)  */
#define GUC_MIN_DEAD_TUPS    "pg_avac.min_dead_tuples"   /* minimum dead rows before we care     */
#define GUC_DML_RATE         "pg_avac.dml_rate_threshold"/* DML rows/sec that flags a hot table  */
#define GUC_MAX_VAC_AGE      "pg_avac.max_vacuum_age"    /* seconds since last vacuum (max)      */
#define GUC_PREP_TX_AGE      "pg_avac.prepared_tx_max_age" /* seconds before prepared tx alert   */
#define GUC_DATABASES        "pg_avac.databases"         /* comma-separated list of DBs to watch */
#define GUC_DRY_RUN          "pg_avac.dry_run"           /* log actions but don't execute them   */

/* ----------------------------------------------------------------
 * Default values for GUCs
 * ---------------------------------------------------------------- */
#define DEFAULT_NAPTIME           60     /* wake every 60 s                  */
#define DEFAULT_DEAD_RATIO        0.05   /* 5% dead rows triggers vacuum     */
#define DEFAULT_MIN_DEAD_TUPS     1000   /* ignore tiny tables               */
#define DEFAULT_DML_RATE          100    /* 100 DML rows/s = hot table       */
#define DEFAULT_MAX_VAC_AGE       3600   /* 1 hour without vacuum = stale    */
#define DEFAULT_PREP_TX_AGE       1800   /* 30 min prepared tx = alert       */
#define DEFAULT_DRY_RUN           false

/* ----------------------------------------------------------------
 * Vacuum strategy — what action to take on a flagged table
 * ---------------------------------------------------------------- */
typedef enum VacStrategy
{
    STRAT_NONE = 0,       /* table is healthy, skip                        */
    STRAT_ANALYZE,        /* only stats are stale                          */
    STRAT_VACUUM,         /* standard VACUUM                               */
    STRAT_VACUUM_ANALYZE, /* VACUUM + ANALYZE (most common)                */
    STRAT_VACUUM_FULL,    /* too bloated — alert DBA, do not auto-run      */
    STRAT_SUGGEST_CONFIG  /* high-churn table needs storage param tuning   */
} VacStrategy;

/* ----------------------------------------------------------------
 * Per-table stats snapshot — captured each wake cycle
 * ---------------------------------------------------------------- */
typedef struct TableStats
{
    Oid         relid;
    NameData    relname;
    NameData    schemaname;

    int64       n_live_tup;
    int64       n_dead_tup;
    int64       n_ins_since_vacuum;   /* pg_stat_user_tables.n_ins_since_vacuum  */
    float8      dead_ratio;           /* n_dead_tup / (n_live_tup + n_dead_tup) */

    /* DML deltas computed between two snapshots */
    int64       dml_delta;            /* total inserts+updates+deletes since last cycle */
    float8      dml_rate;             /* dml_delta / elapsed seconds                   */

    TimestampTz last_vacuum;
    TimestampTz last_analyze;
    int32       vac_age_secs;         /* seconds since last vacuum                     */

    VacStrategy strategy;             /* decision made by the scoring engine           */
} TableStats;

/* ----------------------------------------------------------------
 * Prepared transaction info — captured from pg_prepared_xacts
 * ---------------------------------------------------------------- */
typedef struct PrepTxInfo
{
    char        gid[256];        /* global transaction identifier          */
    TransactionId xid;           /* the XID that's anchoring the horizon   */
    int32       age_secs;        /* how old in seconds                     */
    NameData    owner;           /* role that issued PREPARE TRANSACTION   */
    NameData    database;        /* database it belongs to                 */
} PrepTxInfo;

/* ----------------------------------------------------------------
 * Config suggestion — emitted for STRAT_SUGGEST_CONFIG tables
 * ---------------------------------------------------------------- */
typedef struct ConfigSuggestion
{
    Oid         relid;
    NameData    relname;
    char        param[64];       /* e.g. "autovacuum_vacuum_scale_factor"  */
    char        current_val[64];
    char        suggested_val[64];
    char        reason[256];
} ConfigSuggestion;

/* ----------------------------------------------------------------
 * Shared memory state (minimal — we keep most state in SQL tables)
 * ---------------------------------------------------------------- */
#define PG_AVAC_MAGIC  0x50474156   /* "PGAV" */

typedef struct PgAvacSharedState
{
    int         magic;
    bool        worker_active;
    TimestampTz last_cycle_start;
    int32       tables_checked;
    int32       tables_vacuumed;
    int32       alerts_sent;
} PgAvacSharedState;

/* ----------------------------------------------------------------
 * Function prototypes (implemented in pg_avac.c)
 * ---------------------------------------------------------------- */
extern void pg_avac_main(Datum main_arg);     /* bgworker entry point */

#endif /* PG_AVAC_H */
