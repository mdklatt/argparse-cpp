## CMake build file for the argparse library.
##
## This will build the library and its test suite. Compiled binaries will be
## written to build/${CMAKE_BUILD_TYPE}.
##
cmake_minimum_required(VERSION 2.8.12)

project(argparse)

set(LIB_FILES
    src/action.cpp
    src/action.hpp
    src/util.cpp
    src/util.hpp
)

include_directories(src)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -Wall")
add_library(${PROJECT_NAME} ${LIB_FILES})

function(install)
    # Disable install for test directory.
endfunction()
add_subdirectory(test)
