cmake_minimum_required (VERSION 3.0)

project (StringPermutations)

add_executable(${PROJECT_NAME} main.cpp)
add_executable(${PROJECT_NAME}Swap swap.cpp)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME}Swap PROPERTY CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wpedantic -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-save-temps") 
set_target_properties(${PROJECT_NAME}Swap PROPERTIES COMPILE_FLAGS "-save-temps") 