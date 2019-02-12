cmake_minimum_required(VERSION 3.5)

# SET(CMAKE_CXX_COMPILER g++)
SET(CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(GLOBAL PROPERTY CXX_STANDARD 14)


include_directories(${CMAKE_CURRENT_SOURCE_DIR})
project(w-utils CXX)
add_custom_target(data COMMAND dir SOURCES README.md)

add_subdirectory(utils/cat)
add_subdirectory(utils/cp)
add_subdirectory(utils/false)
add_subdirectory(utils/ls)




