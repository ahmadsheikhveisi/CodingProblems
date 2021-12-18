cmake_minimum_required (VERSION 3.15)

project (FiboImpl)

add_executable(FiboImpl FiboImpl.cpp)

set_property(TARGET FiboImpl PROPERTY CXX_STANDARD 17)

set_target_properties(FiboImpl PROPERTIES COMPILE_FLAGS "-save-temps") 

