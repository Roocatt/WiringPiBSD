/*
 * softServo.h:
 *	Provide N channels of software driven PWM suitable for RC
 *	servo motors.
 *	Copyright (c) 2012 Gordon Henderson
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

#ifndef __SOFT_SERVO_H__
#define __SOFT_SERVO_H__

#ifdef __cplusplus
extern "C" {
#endif

extern void softServoWrite(int, int);
extern int softServoSetup(int, int, int, int, int, int, int, int);

#ifdef __cplusplus
}
#endif

#endif /* __SOFT_SERVO_H__ */
