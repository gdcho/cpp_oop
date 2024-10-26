cmake_minimum_required(VERSION 3.13)
project(multiset)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(multiset
        multiset.cpp)
