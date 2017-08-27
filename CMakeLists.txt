cmake_minimum_required(VERSION 3.6)
project(TickTackToe)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp board.h board.cpp Game.h Game.cpp)
add_executable(TickTackToe ${SOURCE_FILES})