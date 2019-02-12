cmake_minimum_required(VERSION 3.10)

set_property(GLOBAL PROPERTY CXX_STANDARD 17)

project(cp CXX)
add_executable(${PROJECT_NAME} "cp.cpp" "cp-options.cpp" "cp-std.cpp" "cp-boost.cpp" "cp-linux.cpp" "cp.h")
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)


if (WIN32)
   target_compile_definitions(${PROJECT_NAME} PUBLIC BOOST_ALL_DYN_LINK=1)
endif (WIN32)
find_package(Boost COMPONENTS system filesystem REQUIRED)

target_link_libraries(${PROJECT_NAME}
  ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY} stdc++fs
)
target_include_directories( ${PROJECT_NAME} PUBLIC
  ${Boost_INCLUDE_DIRS}
  ${CMAKE_CURRENT_SOURCE_DIR}/../../shared/cxxopts/include
)


 target_include_directories( ${PROJECT_NAME} PUBLIC
   ${Boost_INCLUDE_DIRS}
   ${CMAKE_CURRENT_SOURCE_DIR}/../../shared/cxxopts/include
 )




