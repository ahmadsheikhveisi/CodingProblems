cmake_minimum_required (VERSION 3.0)

project (HexBinStringCompare)

add_library(${PROJECT_NAME} STATIC HexBinStringCompare.cpp HexBinStringCompare.hpp)
add_executable(${PROJECT_NAME}Exe main.cpp)
add_executable(${PROJECT_NAME}Test test.cpp)

target_link_libraries(${PROJECT_NAME}Exe ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}Test ${PROJECT_NAME} gtest_main)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME}Exe PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME}Test PROPERTY CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wpedantic -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-save-temps")
set_target_properties(${PROJECT_NAME}Exe PROPERTIES COMPILE_FLAGS "-save-temps")
set_target_properties(${PROJECT_NAME}Test PROPERTIES COMPILE_FLAGS "-save-temps")


include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}Test)
