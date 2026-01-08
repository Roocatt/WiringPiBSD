/* This file is an exception to the broader license as it is *not* licensed under the LGPL-3.0. */
/* Copyright 2026 Roos Catling-Tate
 *
 * Permission to use, copy, modify, and/or distribute this software for any purpose with or
 * without fee is hereby granted, provided that the above copyright notice and this permission
 * notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED “AS IS” AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR
 * IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef WIRINGPI_DTB_H
#define WIRINGPI_DTB_H

#define FDT_BEGIN_NODE 0x00000001
#define FDT_END_NODE 0x00000002
#define FDT_PROP 0x00000003
#define FDT_NOP 0x00000004
#define FDT_END 0x00000009

typedef struct {
	uint32_t magic_number;
	uint32_t total_len;
	uint32_t dt_struct_offset;
	uint32_t dt_strings_offset;
	uint32_t mem_rsvmap_offset;
	uint32_t version;
	uint32_t last_comp_version;
	uint32_t boot_physical_cpuid;
	uint32_t dt_strings_len;
	uint32_t dt_struct_len;
} dtb_header_t;

typedef struct {
	uint32_t len;
	uint32_t name_offset;
} dtb_prop_t;

uint8_t	*dtb_prop_find(uint8_t *, char *, uint32_t *)

#endif /* WIRINGPI_DTB_H */
