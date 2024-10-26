cmake_minimum_required(VERSION 3.13)
project(entry)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(entry
        entry.cpp
        entry.hpp
        entrytest.cpp)
