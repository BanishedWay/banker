cmake_minimum_required(VERSION 3.17)
project(banker)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")

add_executable(banker main.cpp banker.h banker.cpp)