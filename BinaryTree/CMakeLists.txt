cmake_minimum_required (VERSION 3.6)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()


## Binary Tree

project (BinaryTree)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-save-temps")

# Tests
set(BINARY_TREE_TEST BinaryTreeTests)
add_executable(${BINARY_TREE_TEST} binary_tree_test.cpp)
target_link_libraries(${BINARY_TREE_TEST} gtest_main ${PROJECT_NAME})
set_property(TARGET ${BINARY_TREE_TEST} PROPERTY CXX_STANDARD 17)

include(GoogleTest)
gtest_discover_tests(${BINARY_TREE_TEST})
