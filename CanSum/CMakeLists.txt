cmake_minimum_required (VERSION 3.0)

project (CanSum)

add_executable(CanSum CanSum.cpp)

set_property(TARGET CanSum PROPERTY CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set_target_properties(CanSum PROPERTIES COMPILE_FLAGS "-save-temps") 

