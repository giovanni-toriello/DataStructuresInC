cmake_minimum_required(VERSION 3.23)
project(adtBST C)

set(CMAKE_C_STANDARD 99)

add_executable(adtBST main.c BST.c BST.h item.c item.h)
