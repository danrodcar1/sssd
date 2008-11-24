/*
   SSSD

   Data Provider, private header file

   Copyright (C) Simo Sorce <ssorce@redhat.com>	2008

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __DATA_PROVIDER_H__
#define __DATA_PROVIDER_H__

#include <stdint.h>
#include <sys/un.h>
#include "talloc.h"
#include "events.h"
#include "ldb.h"

#define DATA_PROVIDER_VERSION 0x0001
#define DATA_PROVIDER_SERVICE_NAME "dp"
#define DATA_PROVIDER_PIPE "private/sbus-dp"

#define DATA_PROVIDER_DB_FILE "sssd.ldb"
#define DATA_PROVIDER_DB_CONF_SEC "config/services/nss"

struct dp_mod_ops {
    int (*check_online)(void *pvt_data, int *reply);
};

#define MOD_OFFLINE 0x0000
#define MOD_ONLINE  0x0001

struct dp_mod_ctx;
typedef int (*sssm_init_fn_t)(struct dp_mod_ctx *);

struct dp_mod_ctx {
    struct dp_ctx *dp_ctx;
    const char *name;
    const char *domain;
    struct dp_mod_ops *ops;
    void *pvt_data;
};

struct dp_ctx {
    struct event_context *ev;
    struct confdb_ctx *cdb;
    struct ldb_context *ldb;
    struct service_sbus_ctx *ss_ctx;
    struct dp_mod_ctx **modules;
};

struct dp_client {
    struct dp_ctx *dpctx;
    DBusConnection *conn;
};

#endif /* __DATA_PROVIDER_ */
