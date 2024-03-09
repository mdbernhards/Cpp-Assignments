cmake_minimum_required(VERSION 3.26)
project(Redo)

set(CMAKE_CXX_STANDARD 17)

add_executable(Redo main.cpp moneyDatabase.cpp moneyDatabase.h deposit.h)
