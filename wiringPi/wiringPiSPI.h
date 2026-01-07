/*
 * wiringPiSPI.h:
 *	Simplified SPI access routines
 *	Copyright (c) 2012-2025 Gordon Henderson and contributors
 ***********************************************************************
 * This file is part of wiringPi:
 *	https://github.com/WiringPi/WiringPi/
 *
 *    wiringPi is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as
 *    published by the Free Software Foundation, either version 3 of the
 *    License, or (at your option) any later version.
 *
 *    wiringPi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with wiringPi.
 *    If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************
 */

#ifndef __WIRING_PI_SPI_H__
#define __WIRING_PI_SPI_H__

#ifdef __cplusplus
extern "C" {
#endif

int wiringPiSPIGetFd(int);
int wiringPiSPIDataRW(int, unsigned char *, int);
int wiringPiSPISetupMode(int, int, int);
int wiringPiSPISetup(int, int);
int wiringPiSPIClose(const int); // Interface 3.5

// Interface 3.5
int wiringPiSPIxGetFd(const int, const int);
int wiringPiSPIxDataRW(const int, const int, unsigned char *, const int);
int wiringPiSPIxSetupMode(const int, const int, const int, const int);
int wiringPiSPIxSetup(const int, const int, const int);
int wiringPiSPIxClose(const int, const int);

#ifdef __cplusplus
}
#endif

#endif /* __WIRING_PI_SPI_H__ */
