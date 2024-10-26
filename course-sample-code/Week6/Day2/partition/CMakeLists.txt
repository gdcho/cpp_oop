cmake_minimum_required(VERSION 3.13)
project(partition)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(partition
        partition.cpp)
