cmake_minimum_required (VERSION 2.8.11)
project (libutil)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -ggdb")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -ggdb -std=c++11")

include_directories (${CMAKE_CURRENT_SOURCE_DIR})

# add_subdirectory (src)
add_subdirectory (test)
