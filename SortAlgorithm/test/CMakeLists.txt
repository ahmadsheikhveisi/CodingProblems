cmake_minimum_required(VERSION 3.5)

project(SortAlgorithmTest LANGUAGES CXX VERSION 1.0 DESCRIPTION "Sort Algorithm Test")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} sort_algorithms_tests.cpp)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        SortAlgorithm
        gtest_main
)
