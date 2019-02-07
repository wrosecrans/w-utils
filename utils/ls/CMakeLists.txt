cmake_minimum_required(VERSION 3.5)

set_property(GLOBAL PROPERTY CXX_STANDARD 14)

project(ls CXX)
add_executable(${PROJECT_NAME} "ls.cpp" "ls.h" "ls-options.cpp" "ls-boost.cpp")
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)


 if (WIN32)
    target_compile_definitions(${PROJECT_NAME} PUBLIC BOOST_ALL_DYN_LINK=1)
 endif (WIN32)
 find_package(Boost COMPONENTS system filesystem REQUIRED)

 target_link_libraries(${PROJECT_NAME}
   ${Boost_FILESYSTEM_LIBRARY}
   ${Boost_SYSTEM_LIBRARY}
 )
 target_include_directories( ${PROJECT_NAME} PUBLIC
   ${Boost_INCLUDE_DIRS}
   ${CMAKE_CURRENT_SOURCE_DIR}/../../shared/cxxopts/include
 )

# Adding a useless target will make files show up in an IDE.
add_custom_target(ls-data COMMAND dir SOURCES mktest)


