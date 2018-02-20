/*
 * This file is part of the KNOT Project
 *
 * Copyright (c) 2018, CESAR. All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef __SESSION_H__
#define __SESSION_H__

#include <stdint.h>

#include "node.h"
#include "proto.h"

typedef ssize_t (*on_data)(int node_socket, int proto_socket,
	const void *ipdu, size_t ipdulen,
	void *opdu, size_t opdulen);

int session_create(struct node_ops *node_ops, struct proto_ops *proto_ops,
	int client_socket, on_data on_data);

void session_destroy_all(void);

#endif /* __SESSION_H__ */