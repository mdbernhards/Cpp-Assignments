cmake_minimum_required(VERSION 3.20)
project(Assignment7 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Assignment7 main.cpp Rational.cpp Rational.h)
target_compile_features(Assignment7 PRIVATE cxx_std_20)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_compile_options(Assignment7 PRIVATE -Wall -Wextra -pedantic -fsanitize=address -fno-omit-frame-pointer)
target_link_options(Assignment7 PRIVATE -fsanitize=address)
