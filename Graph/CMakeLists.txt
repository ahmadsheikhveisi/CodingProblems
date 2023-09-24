cmake_minimum_required (VERSION 3.6)

project (Graph)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-save-temps")


set(GRAPH_TEST GraphTests)
add_executable(${GRAPH_TEST} tests.cpp)
target_link_libraries(${GRAPH_TEST} gtest_main ${PROJECT_NAME})
set_property(TARGET ${GRAPH_TEST} PROPERTY CXX_STANDARD 17)

include(GoogleTest)
gtest_discover_tests(${GRAPH_TEST})
