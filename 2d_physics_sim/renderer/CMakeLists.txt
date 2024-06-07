cmake_minimum_required(VERSION 3.10)

add_library(renderer STATIC display.cpp framebuffer.cpp)

target_include_directories(renderer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(renderer PUBLIC tools)

