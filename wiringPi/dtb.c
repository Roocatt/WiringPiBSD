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

/* Reference Documentation:
 *
 * https://devicetree-specification.readthedocs.io/en/stable/flattened-format.html
 */

#include <sys/endian.h>
#include <stdio.h>

#include <stdint.h>
#include <string.h>

#include "dtb.h"

static const uint8_t dtb_magic_number[] = { 0xd0, 0x0d, 0xfe, 0xed };


/* TODO incomplete */
uint8_t *
dtb_prop_find(uint8_t *dtb_data, char *find_name, size_t *find_name_len)
{
	dtb_header_t *header;
	dtb_prop_t *prop_cursor;
	uint32_t struct_len, string_len, prop_val_len, val;
	uint8_t *struct_pos, *string_pos, *cursor, *name, *ret;

	val = be32toh((uint32_t)*data);

	if (!strncmp((char *)&val, dtb_magic_number, sizeof(dtb_magic_number))))
		return (NULL);

	header = (dtb_header_t *)dtb_data;
	struct_pos = dtb_data + be32toh(header->dt_struct_offset);
	struct_len = be32toh(header->dt_struct_len);
	string_pos = dtb_data + be32toh(header->dt_strings_offset);

	for (int i = 0; i < struct_len; i += sizeof(uint32_t)) {
		cursor = struct_pos + i;
		val = be32toh(*((uint32_t *)cursor));

		if (val == FDT_PROP) {
			prop_cursor = (dtb_prop_t *)(cursor + sizeof(uint32_t));
			prop_val_len = be32toh(prop_cursor->len);
			name = (char *)dtb_data + be32toh(header->dt_strings_offset) + be32toh(prop_cursor->name_offset);
			if (strcmp(name, find_name)) {
				*find_name_len = be32toh(prop_cursor->len);
				return ((uint8_t *)(prop_cursor + sizeof(dtb_prop_t)));
			}

			i += sizeof(dtb_prop_t) + (sizeof(uint32_t) - (prop_val_len % sizeof(uint32_t))) + prop_val_len;
			cursor = struct_pos + i;
		}
	}
	return (NULL);
}