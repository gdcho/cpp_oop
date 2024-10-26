cmake_minimum_required(VERSION 3.22)
project(date)

set(CMAKE_CXX_STANDARD 14)

add_executable(date Date.cpp Date.hpp DateTester.cpp)
