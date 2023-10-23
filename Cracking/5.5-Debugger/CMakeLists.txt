cmake_minimum_required(VERSION 3.6)

project(Debugger)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} INTERFACE BitTools)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-save-temps")


add_executable(${PROJECT_NAME}_test tests.cpp)
target_link_libraries(${PROJECT_NAME}_test gtest_main ${PROJECT_NAME})
set_property(TARGET ${PROJECT_NAME}_test PROPERTY CXX_STANDARD 17)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_test)