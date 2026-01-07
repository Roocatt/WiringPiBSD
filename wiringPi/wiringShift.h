/*
 * wiringShift.h:
 *	Emulate some of the Arduino wiring functionality.
 *
 * Copyright (c) 2009-2012 Gordon Henderson.
 ***********************************************************************
 * This file is part of wiringPi:
 *	https://github.com/WiringPi/WiringPi/
 *
 *    wiringPi is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    wiringPi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public License
 *    along with wiringPi.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************
 */

#ifndef __WIRINGSHIFT_H__
#define __WIRINGSHIFT_H__

#define LSBFIRST 0
#define MSBFIRST 1

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

extern uint8_t shiftIn(uint8_t, uint8_t, uint8_t);
extern void shiftOut(uint8_t, uint8_t, uint8_t, uint8_t);

#ifdef __cplusplus
}
#endif

#endif /* __WIRINGSHIFT_H__ */
