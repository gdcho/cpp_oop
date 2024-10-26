cmake_minimum_required(VERSION 3.12)
project(SubjectObserver)

set(CMAKE_CXX_STANDARD 14)

add_executable(SubjectObserver main.cpp Subject.cpp Subject.hpp Observer.cpp Observer.hpp Game.cpp Game.hpp State.hpp HighScore.cpp HighScore.hpp Screens.cpp Screens.hpp)