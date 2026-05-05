MODULE_big   = pg_avac
OBJS         = pg_avac.o

EXTENSION    = pg_avac
DATA         = pg_avac--1.0.sql
PG_CONFIG   ?= pg_config

PG_CPPFLAGS  = -I$(shell $(PG_CONFIG) --includedir-server)

PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
