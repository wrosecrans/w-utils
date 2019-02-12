cmake_minimum_required(VERSION 3.5)

set_property(GLOBAL PROPERTY CXX_STANDARD 14)

project(cat CXX)
add_executable(${PROJECT_NAME} "cat.cpp")
