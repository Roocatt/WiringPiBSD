# January 20, 2026 - Roos Catling-Tate

# TODO makefiles are renamed to old.make wherever present to serve as reference for now.
# Delete these after fully moving to CMake.

cmake_minimum_required(VERSION 3.24)

# TODO Copy-pasted cross compile cmake stuff. Do this right.
include("cmake/netbsd-aarch64-cross-compile.cmake")

project(wiringPiBSD C)

add_subdirectory(wiringPi)
add_subdirectory(devLib)
add_subdirectory(gpio)
add_subdirectory(wiringPiD)

target_include_directories(wiringPiD PRIVATE ${CMAKE_SOURCE_DIR}/wiringPi/include)

# TODO add target for pins
# TODO add target for examples