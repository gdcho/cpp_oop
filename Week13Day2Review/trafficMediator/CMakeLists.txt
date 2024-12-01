cmake_minimum_required(VERSION 3.25)
project(trafficMediator)

set(CMAKE_CXX_STANDARD 17)

add_executable(trafficMediator main.cpp mediator.cpp mediator.hpp components.cpp components.hpp)
