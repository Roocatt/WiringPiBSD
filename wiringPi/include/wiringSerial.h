/*
 * wiringSerial.h:
 *	Handle a serial port
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

#ifndef __WIRINGSERIAL_H__
#define __WIRINGSERIAL_H__

#ifdef __cplusplus
extern "C" {
#endif

extern int serialOpen(const char *, const int);
extern void serialClose(const int);
extern void serialFlush(const int);
extern void serialPutchar(const int, const unsigned char);
extern void serialPuts(const int, const char *);
extern void serialPrintf(const int, const char *, ...);
extern int serialDataAvail(const int);
extern int serialGetchar(const int);

#ifdef __cplusplus
}
#endif

#endif /* __WIRINGSERIAL_H__ */
