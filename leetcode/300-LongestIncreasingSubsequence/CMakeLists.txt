
project(leetcode_300_LongestIncreasingSubsequence)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} solution_test.cpp)

target_link_libraries(${PROJECT_NAME} gtest_main)
