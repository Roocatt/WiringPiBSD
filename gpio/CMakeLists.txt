cmake_minimum_required(VERSION 3.24)

add_executable(gpio src/gpio.c src/readall.c)
target_include_directories(gpio PRIVATE ${CMAKE_SOURCE_DIR}/wiringPi/include)