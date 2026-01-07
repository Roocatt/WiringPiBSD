/*
 * network.h:
 *	Part of wiringPiD
 *	Copyright (c) 2012-2017 Gordon Henderson
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

#ifndef __NETWORK_H__
#define __NETWORK_H__

extern char	*getClientIP(void);
extern int	getResponce(int);
extern int	setupServer(int);
extern int	sendGreeting(int);
extern int	sendChallenge(int);
extern int	getResponse(int);
extern int	passwordMatch(const char *);
extern void	closeServer(int);

#endif /* __NETWORK_H__ */