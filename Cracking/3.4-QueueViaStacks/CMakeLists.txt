cmake_minimum_required (VERSION 3.15)

project (QueueStacks)

add_executable(${PROJECT_NAME} main.cpp)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

target_link_libraries(${PROJECT_NAME} StackImpl)
