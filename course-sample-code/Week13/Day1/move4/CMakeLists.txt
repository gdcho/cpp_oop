cmake_minimum_required(VERSION 3.13)
project(move4)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS "-fno-elide-constructors") # Disable copy elision


include_directories(.)

add_executable(move4
        move4.cpp)
