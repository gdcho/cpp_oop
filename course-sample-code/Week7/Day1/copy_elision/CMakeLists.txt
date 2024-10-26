cmake_minimum_required(VERSION 3.13)
project(copy_elision)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(copy_elision
        copy_elision.cpp)
