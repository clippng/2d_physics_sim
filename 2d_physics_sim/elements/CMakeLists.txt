cmake_minimum_required(VERSION 3.10)

add_library(elements STATIC block.cpp)

target_include_directories(elements PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(elements PUBLIC tools)

