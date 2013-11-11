/*!The Treasure Box Library
 * 
 * TBox is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 * 
 * TBox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with TBox; 
 * If not, see <a href="http://www.gnu.org/licenses/"> http://www.gnu.org/licenses/</a>
 * 
 * Copyright (C) 2009 - 2012, ruki All rights reserved.
 *
 * @author		ruki
 * @file		spak.h
 * @ingroup 	platform
 *
 */
#ifndef TB_PLATFROM_UNIX_ASIO_REACTOR_SPAK_H
#define TB_PLATFROM_UNIX_ASIO_REACTOR_SPAK_H


/* ///////////////////////////////////////////////////////////////////////
 * includes
 */
#include "prefix.h"
#if defined(TB_CONFIG_ASIO_SPAK_HAVE_EVENTFD)
# 	include "./spak/eventfd.h"
#elif defined(TB_CONFIG_ASIO_SPAK_HAVE_PIPE)
# 	include "./spak/pipe.h"
#else
# 	include "./spak/sock.h"
#endif

#endif
