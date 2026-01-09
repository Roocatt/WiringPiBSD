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

#include <sys/endian.h>
#include <sys/types.h>
#include <sys/ioctl.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dev/ofw/openfirmio.h>

#include "ofw.h"

int
ofw_fetch(uint32_t node, char *name, uint32_t *val)
{
	struct iocdesc desc;
	int fd;
	uint32_t rval;
	char buf[4];

	fd = open(OFW_DEV_PATH, O_RDWR);
	if (fd < 0)
		return (1);

	desc.of_nodeid = node;
	desc.of_name = name;
	desc.of_namelen = strlen(name);
	desc.of_buf = buf;
	desc.of_buflen = 4;

	if (ioctl(fd, OFIOCGET, &desc) < 0) {
		close(fd);
		return (2);
	}

	rval = *((uint32_t *)desc.of_buf);
	*val = rval;
	close(fd);

	return (0);
}