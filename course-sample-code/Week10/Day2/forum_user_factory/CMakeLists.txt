cmake_minimum_required(VERSION 3.13)
project(forum_user_factory)

set(CMAKE_CXX_STANDARD 14)

add_executable(forum_user_factory main.cpp user.cpp user.hpp factory.cpp factory.hpp)