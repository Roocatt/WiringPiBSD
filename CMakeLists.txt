# January 20, 2026 - Roos Catling-Tate

cmake_minimum_required(VERSION 3.24)

# TODO Copy-pasted cross compile cmake stuff. Do this right.
include("cmake/netbsd-aarch64-cross-compile.cmake")

project(wiringPi C)

add_library(wiringPi SHARED wiringPi/ads1115.c wiringPi/ads1115.h wiringPi/bmp180.c wiringPi/bmp180.h wiringPi/drcNet.c
	wiringPi/drcNet.h wiringPi/drcSerial.c wiringPi/drcSerial.h wiringPi/ds18b20.c wiringPi/ds18b20.h
	wiringPi/dtb.c wiringPi/dtb.h wiringPi/htu21d.c wiringPi/htu21d.h wiringPi/max31855.c wiringPi/max31855.h
	wiringPi/max5322.c wiringPi/max5322.h wiringPi/mcp23008.c wiringPi/mcp23008.h wiringPi/mcp23016.c
	wiringPi/mcp23016.h wiringPi/mcp23016reg.h wiringPi/mcp23017.c wiringPi/mcp23017.h wiringPi/mcp23s08.c
	wiringPi/mcp23s08.h wiringPi/mcp23s17.c wiringPi/mcp23s17.h wiringPi/mcp23x08.h wiringPi/mcp23x0817.h
	wiringPi/mcp3002.c wiringPi/mcp3002.h wiringPi/mcp3004.c wiringPi/mcp3004.h wiringPi/mcp3422.c
	wiringPi/mcp3422.h wiringPi/mcp4802.c wiringPi/mcp4802.h wiringPi/ofw.c wiringPi/ofw.h wiringPi/pcf8574.c
	wiringPi/pcf8574.h wiringPi/pcf8591.c wiringPi/pcf8591.h wiringPi/piHiPri.c wiringPi/piThread.c
	wiringPi/pseudoPins.c wiringPi/pseudoPins.h wiringPi/rht03.c wiringPi/rht03.h wiringPi/sn3218.c
	wiringPi/sn3218.h wiringPi/softPwm.c wiringPi/softPwm.h wiringPi/softServo.c wiringPi/softServo.h
	wiringPi/softTone.c wiringPi/softTone.h wiringPi/sr595.c wiringPi/sr595.h wiringPi/wiringPi.c
	wiringPi/wiringPi.h wiringPi/wiringPiI2C.c wiringPi/wiringPiI2C.h wiringPi/wiringPiLegacy.c
	wiringPi/wiringPiLegacy.h wiringPi/wiringPiSPI.c wiringPi/wiringPiSPI.h wiringPi/WiringpiV1.c
	wiringPi/wiringSerial.c wiringPi/wiringSerial.h wiringPi/wiringShift.c wiringPi/wiringShift.h
	wiringPi/wpiExtensions.c wiringPi/wpiExtensions.h)