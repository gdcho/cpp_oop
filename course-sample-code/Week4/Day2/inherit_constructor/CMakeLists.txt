cmake_minimum_required(VERSION 3.13)
project(inherit_constructor)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(inherit_constructor
        inherit_constructor.cpp)
