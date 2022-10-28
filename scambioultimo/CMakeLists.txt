cmake_minimum_required(VERSION 3.23)
project(scambioultimo C)

set(CMAKE_C_STANDARD 99)

add_executable(scambioultimo main.c item.c item.h list.c list.h esame.c esame.h)
