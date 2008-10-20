/* Gearman server and library
 * Copyright (C) 2008 Brian Aker
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef __GEARMAN_CLIENT_H__
#define __GEARMAN_CLIENT_H__

#include <libgearman/libgearman_config.h>

#ifdef HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#include <libgearman/constants.h>
#include <libgearman/types.h>
#include <libgearman/watchpoint.h>
#include <libgearman/server.h>

#ifdef __cplusplus
extern "C" {
#endif

/* These are Private and should not be used by applications */
#define GEARMAN_H_VERSION_STRING_LENGTH 12

struct gearman_worker_st {
  bool is_allocated;
  gearman_server_list_st list;
};

/* Public API */

/* Create and destory worker structures */
gearman_worker_st *gearman_worker_create(gearman_worker_st *worker);
void gearman_worker_free(gearman_worker_st *worker);
gearman_worker_st *gearman_worker_clone(gearman_worker_st *worker);

/* Add a server to the worker */
gearman_return gearman_worker_server_add(gearman_worker_st *worker,
                                         const char *hostname,
                                         uint16_t port);

#ifdef __cplusplus
}
#endif

#endif /* __GEARMAN_CLIENT_H__ */