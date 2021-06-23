cmake_minimum_required(VERSION 3.5)


add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(cref cref.cpp)

target_compile_features(cref PRIVATE cxx_lambda_init_captures)