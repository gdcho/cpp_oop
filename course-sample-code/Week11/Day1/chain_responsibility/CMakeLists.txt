cmake_minimum_required(VERSION 3.13)
project(chain_responsibility)

set(CMAKE_CXX_STANDARD 14)

add_executable(chain_responsibility main.cpp handlers.cpp handlers.hpp StudentAccount.cpp StudentAccount.hpp EnrolmentApplicationForm.cpp EnrolmentApplicationForm.hpp)