cmake_minimum_required(VERSION 3.23)
project(adtQueue C)

set(CMAKE_C_STANDARD 99)

add_executable(adtQueue main.c queue.c queue.h punto.c punto.h)
