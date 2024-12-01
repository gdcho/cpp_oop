cmake_minimum_required(VERSION 3.25)
project(dogState)

set(CMAKE_CXX_STANDARD 17)

add_executable(dogState main.cpp state.hpp context.hpp)
