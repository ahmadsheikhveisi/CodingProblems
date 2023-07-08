cmake_minimum_required (VERSION 3.15)

project (FutureExample)

add_executable(${PROJECT_NAME}_SimpleWorker main.cpp)

set_property(TARGET ${PROJECT_NAME}_SimpleWorker PROPERTY CXX_STANDARD 17)

target_link_libraries(${PROJECT_NAME}_SimpleWorker pthread)
