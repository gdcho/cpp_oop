cmake_minimum_required(VERSION 3.13)
project(game_state_pattern)

set(CMAKE_CXX_STANDARD 14)

add_executable(game_state_pattern main.cpp state.cpp state.hpp context.cpp context.hpp)