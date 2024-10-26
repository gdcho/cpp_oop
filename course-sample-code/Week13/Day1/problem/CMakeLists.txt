cmake_minimum_required(VERSION 3.13)
project(problem)

set(CMAKE_CXX_STANDARD 14 )
set(CMAKE_CXX_FLAGS "-fno-elide-constructors") # Disable copy elision

include_directories(.)

add_executable(problem
        problem.cpp)
