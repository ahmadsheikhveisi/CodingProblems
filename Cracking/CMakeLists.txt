cmake_minimum_required(VERSION 3.15)

project(Cracking)

add_compile_options(-Wall -Wextra -Wconversion -Wpedantic -Werror)

subdirlist(subdirs ${CMAKE_CURRENT_SOURCE_DIR})
foreach(subdir ${subdirs})
    add_subdirectory(${subdir})
endforeach()
