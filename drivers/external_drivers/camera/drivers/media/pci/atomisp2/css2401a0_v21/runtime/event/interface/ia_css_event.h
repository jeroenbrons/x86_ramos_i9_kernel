/*
 * Support for Intel Camera Imaging ISP subsystem.
 *
 * Copyright (c) 2010 - 2014 Intel Corporation. All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 */

#ifndef _IA_CSS_EVENT_H
#define _IA_CSS_EVENT_H

#ifndef __KERNEL__
/* bool */
#include <stdbool.h>
/* NULL */
#include <stddef.h>
#endif

#include "system_types.h"

#include "ia_css_binary.h"
#include "sh_css_internal.h"
#include "ia_css_types.h"
#include "sw_event_global.h"    /*event macros.TODO : Change File Name..???*/

bool ia_css_event_encode(
	uint8_t	*in,
	uint8_t	nr,
	uint32_t	*out);

void ia_css_event_decode(
	uint32_t event,
	uint8_t *payload);

#endif /*_IA_CSS_EVENT_H*/
