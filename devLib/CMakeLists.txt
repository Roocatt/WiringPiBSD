cmake_minimum_required(VERSION 3.24)

add_library(devLib SHARED src/ds1302.c src/ds1302.h src/font.h src/gertboard.c src/gertboard.h
	src/lcd.c src/lcd.h src/lcd128x64.c src/lcd128x64.h src/maxdetect.c src/maxdetect.h
	src/piFace.c src/piFace.h src/piFaceOld.c src/piGlow.c src/piGlow.h src/piNes.c
	src/piNes.h src/scrollPhat.c src/scrollPhat.h src/scrollPhatFont.h)

target_include_directories(devLib PRIVATE ${CMAKE_SOURCE_DIR}/wiringPi/include)