/* This file is an exception to the broader licence as it is *not* licensed under the LGPL-3.0. */
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

#include <sys/ioctl.h>
#include <sys/gpio.h>

#include <fcntl.h>
#include <poll.h>
#include <unistd.h>
#include <string.h>

#include "gpioirq.h"

static int gpioirq_fd = -1;

int
gpioirq_get_fd(void)
{
	int fd;

	if (gpioirq_fd == -1) {
		fd = open("/dev/gpioirq0", O_RDONLY);
		if (fd < 0)
			goto err;
		gpioirq_fd = fd;
	} else
		fd = gpioirq_fd;

err:
	return (fd);
}

int
gpioirq_poll_any(int ms, uint64_t *ts)
{
	return (gpioirq_poll(-1, -1, ms, ts));
}

int
gpioirq_poll_pin(int pin, int ms, uint64_t *ts)
{
	return (gpioirq_poll(-1, pin, ms, ts));
}

int
gpioirq_poll(int unit, int pin, int ms, uint64_t *ts)
{
	struct pollfd pfd = {0};
	struct timespec timespec;
	struct gpioirq_event event = {0};
	int fd, res = -1;

	if ((fd = gpioirq_get_fd()) < 0)
		goto end;

	pfd.fd = fd;
	pfd.events = POLLIN | POLLPRI;
	if ((res = poll(&pfd, 1, ms)) > 0 && pfd.revents & POLLIN
	    && read(fd, &event, sizeof(event)) == sizeof(event)
	    && (unit == -1 || event.unit == unit)
	    && (pin == -1 || event.pin == pin)) {
		clock_gettime(CLOCK_REALTIME, &timespec);
		*ts = (uint64_t)(timespec.tv_nsec / 1000L) + (uint64_t)(timespec.tv_sec * 1000000L);
	}

end:
	return (res);
}

int
gpioirq_attach(int gpio_fd, int pin, uint32_t mask, uint32_t flags)
{
	struct gpio_attach attach = {0};

	strncpy(attach.ga_dvname, "gpioirq", sizeof(attach.ga_dvname));
	attach.ga_offset = pin;
	attach.ga_mask = mask;
	attach.ga_flags = flags;

	return (ioctl(gpio_fd, GPIOATTACH, &attach));
}