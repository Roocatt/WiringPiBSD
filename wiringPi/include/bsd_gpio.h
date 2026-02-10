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

#ifndef WIRINGPIBSD_BSD_GPIO_H
#define WIRINGPIBSD_BSD_GPIO_H

#if defined(__cplusplus)
extern "C" {
#endif

/* Specific BSD version definitions */
#ifdef __FreeBSD__
#define GPIOWRITE GPIOSET
typedef struct gpio_pin gpio_set_t;
#else
typedef struct gpio_set gpio_set_t;
#endif

int	bsd_spi_init(int *, int, int, int);
int	bsd_spi_ioctl(int, unsigned char *, size_t, const unsigned char *, size_t);

#if defined(__cplusplus)
}
#endif

#endif /* WIRINGPIBSD_BSD_GPIO_H */
