cmake_minimum_required(VERSION 3.13)
project(game_abstract_factory)

set(CMAKE_CXX_STANDARD 14)

add_executable(game_abstract_factory main.cpp Friendly.cpp Friendly.hpp Enemy.cpp Enemy.hpp Animal.cpp Animal.hpp CharacterFactory.cpp CharacterFactory.hpp)