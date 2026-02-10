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

#ifdef __FreeBSD__
#include <sys/spigenio.h>
#else
#include <dev/spi/spi_io.h>
#endif

#include <sys/ioctl.h>
#include <sys/stat.h>

#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#include "bsd_gpio.h"

static char *spi_dev_defaults[] = {
	"/dev/spiN",
	"/dev/spi0.N",
	"/dev/spidevN",
	"/dev/spidev0.N",
#ifdef __FreeBSD__
	"/dev/spigenN"
#endif
};

static char	*find_spi_dev_path(uint8_t);
static char *
find_spi_dev_path(const uint8_t spi_channel)
{
	struct stat s;
	size_t i;
	char *cur_path = NULL, *res = NULL;

	for (i = 0; i < sizeof(spi_dev_defaults) / sizeof(spi_dev_defaults[0]); i++) {
		cur_path = spi_dev_defaults[i];
		cur_path[strlen(cur_path) - 1] = spi_channel == 0 ? '0' : '1';
		if (stat(cur_path, &s) != 0) {
			res = cur_path;
			goto end;
		}
	}

	end:
		return (res);
}

int
bsd_spi_init(int *spi_fd, int spi_channel, int spi_mode, int spi_clock)
{
#ifndef __FreeBSD__
	spi_ioctl_configure_t spi_cfg = { 0 };
#endif
	int res, spidev_fd;
	char *spidev_path;

	spidev_path = find_spi_dev_path(spi_channel);

	if (spidev_path == NULL) {
		res = -1;
		goto err;
	}

	spidev_fd = open(spidev_path, O_RDWR);
	if (spidev_fd < 0) {
		res = -1;
		goto err;
	}
#ifdef __FreeBSD__
	if ((res = ioctl(spidev_fd, SPIGENIOC_SET_CLOCK_SPEED))) {
		close(spidev_fd);
		goto err;
	}
	if ((res = ioctl(spidev_fd, SPIGENIOC_SET_SPI_MODE))) {
		close(spidev_fd);
		goto err;
	}
#else
	spi_cfg.sic_mode = spi_mode;
	spi_cfg.sic_speed = spi_clock;

	if ((res = ioctl(spidev_fd, SPI_IOCTL_CONFIGURE, &spi_cfg))) {
		close(spidev_fd);
		goto err;
	}

	*spi_fd = spidev_fd;
#endif

err:
	return (res);
}

int
bsd_spi_ioctl(int fd, unsigned char *read, size_t read_len, const unsigned char *write, size_t write_len)
{
	int res;
#ifdef __FreeBSD__
	struct spigen_transfer transfer = {0};

	transfer.st_command.iov_base = write;
	transfer.st_command.iov_len = write_len;
	transfer.st_data.iov_base = read;
	transfer.st_data.iov_len = read_len;

	res = ioctl(fd, SPIGENIOC_TRANSFER, &transfer);
#else
	spi_ioctl_transfer_t tr = {
		.sit_send = write,
		.sit_sendlen = write_len,
		.sit_recv = read,
		.sit_recvlen = read_len,
	};

	res = ioctl(fd, SPI_IOCTL_TRANSFER, &tr);
#endif

	return (res);
}