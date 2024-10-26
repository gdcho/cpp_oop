cmake_minimum_required(VERSION 3.13)
project(Dollar)

set(CMAKE_CXX_STANDARD 14)

add_executable(Dollar main.cpp Dollar.cpp Dollar.hpp Random.cpp Random.hpp)