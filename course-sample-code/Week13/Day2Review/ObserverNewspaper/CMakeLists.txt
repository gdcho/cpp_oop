cmake_minimum_required(VERSION 3.13)
project(ObserverNewspaper)

set(CMAKE_CXX_STANDARD 14)

add_executable(ObserverNewspaper main.cpp Subject.cpp Subject.hpp Observer.cpp Observer.hpp)