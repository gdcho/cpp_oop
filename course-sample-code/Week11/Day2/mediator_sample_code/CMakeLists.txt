cmake_minimum_required(VERSION 3.13)
project(mediator_sample_code)

set(CMAKE_CXX_STANDARD 14)

add_executable(mediator_sample_code main.cpp mediator.cpp mediator.hpp components.cpp components.hpp)