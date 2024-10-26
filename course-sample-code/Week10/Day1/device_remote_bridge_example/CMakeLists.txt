cmake_minimum_required(VERSION 3.13)
project(device_remote_bridge_example)

set(CMAKE_CXX_STANDARD 14)

add_executable(device_remote_bridge_example main.cpp device_implementation.cpp device_implementation.hpp remote_abstraction.cpp remote_abstraction.hpp)