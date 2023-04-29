cmake_minimum_required (VERSION 3.0)

project (SinglyLinkedListImpl)

add_library(${PROJECT_NAME} INTERFACE singly_linked_list.hpp)
target_include_directories(${PROJECT_NAME} SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-save-temps") 

file(GLOB TST_SRC test.cpp)
add_executable(${PROJECT_NAME}_test ${TST_SRC})
target_link_libraries(${PROJECT_NAME}_test gtest_main ${PROJECT_NAME})

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_test)
