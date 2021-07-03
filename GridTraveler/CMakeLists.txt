cmake_minimum_required (VERSION 3.0)

project (GridTraveler)

add_executable(GridTraveler GridTraveler.cpp)

set_property(TARGET GridTraveler PROPERTY CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set_target_properties(GridTraveler PROPERTIES COMPILE_FLAGS "-save-temps") 

