cmake_minimum_required(VERSION 3.20)
project(decorator)

set(CMAKE_CXX_STANDARD 14)

add_executable(decorator decorator.cpp main.cpp factory.cpp)
