cmake_minimum_required(VERSION 3.5.0)
project(Assignment5 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Assignment5 main.cpp outputFile.cpp outputFile.h)

target_compile_features(Assignment5 PRIVATE cxx_std_20)
target_compile_options(Assignment5 PRIVATE -Wall -Wextra -pedantic)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
