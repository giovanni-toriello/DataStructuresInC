cmake_minimum_required(VERSION 3.23)
project(adtStack C)

set(CMAKE_C_STANDARD 99)

add_executable(adtStack stack.c stack.h item.c item.h main.c)
