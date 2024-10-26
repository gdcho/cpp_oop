cmake_minimum_required(VERSION 3.13)
project(random_c)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(random_c
        random_c.cpp)
