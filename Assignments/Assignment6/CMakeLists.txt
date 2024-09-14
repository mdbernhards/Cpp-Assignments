cmake_minimum_required(VERSION 3.20)
project(Assignment6 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Assignment6 main.cpp String.h String.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_compile_options(Assignment6 PRIVATE -Wall -Wextra -pedantic -fsanitize=address -fno-omit-frame-pointer)
target_link_options(Assignment6 PRIVATE -fsanitize=address)
