cmake_minimum_required (VERSION 3.0)

project (StackImpl)

add_library(${PROJECT_NAME} INTERFACE stack.hpp)
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${PROJECT_NAME}_test main.cpp)
target_link_libraries(${PROJECT_NAME}_test ${PROJECT_NAME})

set_property(TARGET ${PROJECT_NAME}_test PROPERTY CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wpedantic -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set_target_properties(${PROJECT_NAME}_test PROPERTIES COMPILE_FLAGS "-save-temps")