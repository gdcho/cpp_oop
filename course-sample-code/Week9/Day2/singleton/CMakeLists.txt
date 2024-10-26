cmake_minimum_required(VERSION 3.13)
project(singleton)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(singleton
        otherFile.cpp otherFile.hpp singleton.hpp main.cpp)
