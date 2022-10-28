cmake_minimum_required(VERSION 3.23)
project(removeStack C)

set(CMAKE_C_STANDARD 99)

add_executable(removeStack main.c item.c item.h stack.c stack.h esame.c esame.h)
