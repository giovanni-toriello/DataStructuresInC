cmake_minimum_required(VERSION 3.23)
project(stack_concat C)

set(CMAKE_C_STANDARD 99)

add_executable(stack_concat main.c stack.h stack.c esame.h esame.c item.c)
