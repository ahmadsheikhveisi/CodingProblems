project(AdjacentPointMinDist)

file(GLOB SRC solution.cpp solution.hpp)

set(LIB_NAME ${PROJECT_NAME})
add_library(${LIB_NAME} STATIC ${SRC})
target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


file(GLOB TST_SRC test.cpp)
add_executable(${PROJECT_NAME}_test ${TST_SRC})
target_link_libraries(${PROJECT_NAME}_test gtest_main ${PROJECT_NAME})

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_test)
