cmake_minimum_required(VERSION 3.15)

project(CoinChaning)

set(CMAKE_CXX_STANDARD 17)

# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
# )
# # For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)

add_executable(CoinChaning main.cpp solution.cpp)
add_executable(CoinChaningTest solution.cpp solution_test.cpp)
target_link_libraries(CoinChaningTest gtest_main)

enable_testing()

include(GoogleTest)
gtest_discover_tests(CoinChaningTest)
