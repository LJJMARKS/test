cmake_minimum_required(VERSION 3.24)
project(vechashmap)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(vechashmap
        main.cpp
        vechashtable.h)
