cmake_minimum_required(VERSION 3.15)

project(CodingProblems)

include(SubDirList.cmake)

subdirlist(subdirs ${CMAKE_CURRENT_SOURCE_DIR})

foreach(subdir ${subdirs})
    add_subdirectory(${subdir})    
endforeach()
