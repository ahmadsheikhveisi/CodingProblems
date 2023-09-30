cmake_minimum_required(VERSION 3.6)

project(ValidateBST)

add_executable(${PROJECT_NAME}_test tests.cpp)
target_link_libraries(${PROJECT_NAME}_test gtest_main BinaryTree)
set_property(TARGET ${PROJECT_NAME}_test PROPERTY CXX_STANDARD 17)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_test)
