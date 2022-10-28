cmake_minimum_required(VERSION 3.23)
project(adtBTree C)

set(CMAKE_C_STANDARD 99)

add_executable(adtBTree main.c stack.c stack.h BTree.c Btree.h item.c item.h esame.c esame.h)
