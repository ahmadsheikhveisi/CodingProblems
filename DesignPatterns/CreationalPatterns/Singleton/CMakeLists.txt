cmake_minimum_required (VERSION 3.15)

project (DesignPatternSingleton)

add_library(NaiveSingleton NaiveSingleton.cpp NaiveSingleton.hpp)
add_library(ThreadSafeSingleton ThreadSafeSingleton.cpp ThreadSafeSingleton.hpp)
add_library(ZeroHandle ZeroHandle.cpp ZeroHandle.hpp)
add_library(MeyerSingleton MeyerSingleton.cpp MeyerSingleton.hpp)

add_executable(SingletonBenchmark SingletonBenchmark.cpp)
target_link_libraries(SingletonBenchmark NaiveSingleton ThreadSafeSingleton ZeroHandle MeyerSingleton benchmark)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} pthread NaiveSingleton ThreadSafeSingleton ZeroHandle MeyerSingleton)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
