cmake_minimum_required(VERSION 3.10) #Same version as mp

#Setting c++ standard the same as mp
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(NotSkyScanner)

#executable for main
add_executable(main entry/main.cpp)