## CMake build file for the argparse library test suite.
##
## This will build a Google Test test runner for all contained tests.
##
project(test_argparse)

set(TEST_FILES
    test_util.cpp
)


add_subdirectory(lib/gtest)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME} ${TEST_FILES})
target_link_libraries(${PROJECT_NAME} argparse gtest gtest_main)
