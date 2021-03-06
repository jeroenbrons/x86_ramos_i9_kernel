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

#ifndef __IA_CSS_OB_PARAM_H
#define __IA_CSS_OB_PARAM_H

#include "type_support.h"
#include "vmem.h"

#define OBAREA_MASK_SIZE 64

/* OB (Optical Black) */
struct sh_css_isp_ob_stream_config {
	unsigned isp_pipe_version;
	unsigned raw_bit_depth;
};

struct sh_css_isp_ob_params {
	int32_t blacklevel_gr;
	int32_t blacklevel_r;
	int32_t blacklevel_b;
	int32_t blacklevel_gb;
	int32_t area_start_bq;
	int32_t area_length_bq;
	int32_t area_length_bq_inverse;
};

struct sh_css_isp_ob_vmem_params {
	VMEM_ARRAY(vmask, OBAREA_MASK_SIZE);
};

#endif /* __IA_CSS_OB_PARAM_H */
