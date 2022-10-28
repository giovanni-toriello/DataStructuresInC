cmake_minimum_required(VERSION 3.23)
project(adtPunto C)

set(CMAKE_C_STANDARD 99)

add_executable(adtPunto main.c punto.c punto.h list.c list.h esame.c esame.h)
