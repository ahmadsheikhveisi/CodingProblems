cmake_minimum_required (VERSION 2.6)

project (FiboImpl)

add_executable(FiboImpl FiboImpl.cpp)

set_property(TARGET FiboImpl PROPERTY CXX_STANDARD 17)

set_target_properties(FiboImpl PROPERTIES COMPILE_FLAGS "-save-temps") 

