cmake_minimum_required(VERSION 3.5)

project(SortAlgorithm LANGUAGES CXX VERSION 1.0 DESCRIPTION "Srt Algorithm")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME}
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_subdirectory(test)
