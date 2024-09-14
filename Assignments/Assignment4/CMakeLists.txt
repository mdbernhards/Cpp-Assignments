cmake_minimum_required(VERSION 3.5.0)
project(Assignment4 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Assignment4 main.cpp options.cpp options.h fileCounts.cpp fileCounts.h counter.cpp counter.h)

target_compile_features(Assignment4 PRIVATE cxx_std_20)
target_compile_options(Assignment4 PRIVATE -Wall -Wextra -pedantic)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
