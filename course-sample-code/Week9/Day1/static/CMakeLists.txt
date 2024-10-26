cmake_minimum_required(VERSION 3.13)
project(static)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(static
        static.cpp)
