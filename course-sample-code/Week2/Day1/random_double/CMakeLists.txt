cmake_minimum_required(VERSION 3.13)
project(random_double)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(random_double
        random_double.cpp)
