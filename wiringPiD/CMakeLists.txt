cmake_minimum_required(VERSION 3.24)

add_executable(wiringPiD src/daemonise.c src/daemonise.h src/drcNetCmd.h src/network.c
	src/network.h src/runRemote.c src/runRemote.h src/wiringpid.c)

target_include_directories(wiringPiD PRIVATE ${CMAKE_SOURCE_DIR}/wiringPi/include)