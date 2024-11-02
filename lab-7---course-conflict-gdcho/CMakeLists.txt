cmake_minimum_required(VERSION 3.20)
project(lab7template)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
include_directories(/Library/Developer/CommandLineTools/usr/include)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab7template main.cpp Course.hpp Course.cpp)
