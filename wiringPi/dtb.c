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


static inline int	dtb_magic_number_present(uint8_t *);
static inline int
dtb_magic_number_present(uint8_t *data)
{
	uint32_t data_num;

	data_num = be32toh((uint32_t)*data);

	return (!strncmp((char *)&data_num, dtb_magic_number, sizeof(dtb_magic_number)));
}

int
dtb_extract(uint8_t *dtb_data, size_t data_len)
{
	dtb_header_t *header;
	dtb_prop_t *prop_cursor;
	int val;
	uint32_t struct_len, string_len, cur_token;
	uint8_t *struct_pos, *string_pos, *cursor, token_following;

	if (dtb_magic_number_present(dtb_data)) {
		return (1);
	}

	header = (dtb_header_t *)dtb_data;

	if (be32toh(header->total_len) > data_len || be32toh(header->dt_struct_offset) > data_len
		    || be32toh(header->dt_strings_offset) > data_len) {
		return (2);
	}

	struct_pos = dtb_data + be32toh(header->dt_struct_offset);
	struct_len = be32toh(header->dt_struct_len);
	string_pos = dtb_data + be32toh(header->dt_strings_offset);
	string_len = be32toh(header->dt_strings_len);

	if (be32toh(header->dt_struct_offset) + struct_len > data_len
		    || be32toh(header->dt_strings_offset) + string_len > data_len)
		return (2);

	cur_token = 0;
	token_following = 0;

	for (int i = 0; i < struct_len / sizeof(uint32_t); i += sizeof(uint32_t)) {
		cursor = struct_pos + i;
		val = be32toh(*((uint32_t *)cursor));

		if (cur_token == FDT_BEGIN_NODE && !token_following) { /* TODO fix this*/
			token_following = 1;
			continue;
		}

		switch (val) {
		case FDT_BEGIN_NODE:
			cur_token = FDT_BEGIN_NODE;
			break;
		case FDT_END_NODE:
			cur_token = FDT_END_NODE;
			break;
		case FDT_PROP:
			if (cur_token == FDT_END) {
				return (3);
			}
			cur_token = FDT_PROP;

			prop_cursor = (dtb_prop_t *)(cursor + sizeof(uint32_t));

			i += sizeof(dtb_prop_t);
			cursor = struct_pos + i;
			break;
		case FDT_NOP:
			cur_token = FDT_NOP;
			break;
		case FDT_END:
			cur_token = FDT_END;
			break;
		}
	}

	return (0);
}