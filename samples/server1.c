/**
 * Copyright (C) 2005-2010 Christoph Rupp (chris@crupp.de).
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or 
 * (at your option) any later version.
 *
 * See files COPYING.* for License information.
 *
 *
 * A simple example which creates a server with one Environment and
 * several Databases
 */

#include <stdio.h>
#include <stdlib.h>
#include <ham/hamsterdb.h>
#include <ham/hamserver.h>

int 
main(void)
{
    ham_db_t *db;
    ham_env_t *env;
    hamserver_t *srv;
    hamserver_config_t cfg;
    ham_status_t st;

    ham_env_new(&env);
    st=ham_env_create(env, "test.db", HAM_ENABLE_TRANSACTIONS, 0644);
    if (st) {
        printf("ham_env_create: %d\n", st);
        exit(-1);
    }

    ham_new(&db);
    st=ham_env_create_db(env, db, 14, HAM_ENABLE_DUPLICATES, 0);
    if (st) {
        printf("ham_env_create_db: %d\n", st);
        exit(-1);
    }
    ham_close(db, 0);

    st=ham_env_create_db(env, db, 13, HAM_ENABLE_DUPLICATES, 0);
    if (st) {
        printf("ham_env_create_db: %d\n", st);
        exit(-1);
    }
    ham_close(db, 0);

    st=ham_env_create_db(env, db, 33, 
                HAM_RECORD_NUMBER|HAM_ENABLE_DUPLICATES, 0);
    if (st) {
        printf("ham_env_create_db: %d\n", st);
        exit(-1);
    }
    ham_close(db, 0);

    cfg.port=8080;
    hamserver_init(&cfg, &srv);
    hamserver_add_env(srv, env, "/test.db");
    
    while (1)
        getchar();

    hamserver_close(srv);
    ham_env_close(env, HAM_AUTO_CLEANUP);
    ham_env_delete(env);
    ham_delete(db);

    return (0);
}
