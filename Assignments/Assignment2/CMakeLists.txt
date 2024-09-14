cmake_minimum_required(VERSION 3.6.0)
project(Assignment2 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Assignment2 main.cpp Dictionary.cpp Dictionary.h TextRedactor.cpp TextRedactor.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
