cmake_minimum_required(VERSION 3.13)
project(const_vs_constexpr)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(const_vs_constexpr
        const_vs_constexpr.cpp)
