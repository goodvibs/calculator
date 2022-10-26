cmake_minimum_required(VERSION 3.21)
project(calculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(calculator main.cpp calculator.cpp calculator.h computation.cpp computation.h util.h)
