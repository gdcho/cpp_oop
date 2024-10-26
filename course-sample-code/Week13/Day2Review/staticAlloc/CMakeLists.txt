cmake_minimum_required(VERSION 3.13)
project(staticAlloc)

set(CMAKE_CXX_STANDARD 14)
set(-fno-elide-constructors)

add_executable(staticAlloc main.cpp)