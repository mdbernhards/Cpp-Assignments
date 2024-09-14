cmake_minimum_required(VERSION 3.22.1)
project(Assignment2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Assignment2 main.cpp Dictionary.h
        Dictionary.cpp
        TextRedactor.cpp
        TextRedactor.h)
