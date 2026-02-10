cmake_minimum_required(VERSION 3.24)

project(wiringPi C)

add_library(wiringPi SHARED src/ads1115.c src/bmp180.c src/drcNet.c src/drcSerial.c src/ds18b20.c
	src/dtb.c src/gpioirq.c src/htu21d.c src/max31855.c src/max5322.c src/mcp23008.c src/mcp23016.c src/mcp23017.c
	src/mcp23s08.c src/mcp23s17.c src/mcp3002.c src/mcp3004.c src/mcp3422.c src/mcp4802.c src/ofw.c src/pcf8574.c
	src/pcf8591.c src/piHiPri.c src/piThread.c src/pseudoPins.c src/rht03.c src/sn3218.c src/softPwm.c
	src/softServo.c src/softTone.c src/sr595.c src/wiringPi.c src/wiringPiI2C.c src/wiringPiLegacy.c
	src/wiringPiSPI.c src/wiringSerial.c src/wiringShift.c src/wpiExtensions.c)
target_include_directories(wiringPi PRIVATE include)