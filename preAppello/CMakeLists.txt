cmake_minimum_required(VERSION 3.23)
project(preAppello C)

set(CMAKE_C_STANDARD 99)

add_executable(preAppello main.c item.c item.h BTree.c BTree.h PQueue.c PQueue.h esame.c esame.h)
