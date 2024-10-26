cmake_minimum_required(VERSION 3.13)
project(upcast_and_slice)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(upcast_and_slice
        upcast_and_slice.cpp)
