cmake_minimum_required (VERSION 3.15)

project (DesignPatternSingleton)

add_library(NaiveSingleton NaiveSingleton.cpp NaiveSingleton.hpp)
add_library(ThreadSafeSingleton ThreadSafeSingleton.cpp ThreadSafeSingleton.hpp)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} pthread NaiveSingleton ThreadSafeSingleton)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
