cmake_minimum_required(VERSION 3.20)
project(lab1template)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 20)

add_executable(lab9template main.cpp
        door.hpp
        maze.hpp
        maze_factory.hpp
        maze_game.hpp
        maze_object.hpp
        room.hpp
        wall.hpp
        door.cpp
)
