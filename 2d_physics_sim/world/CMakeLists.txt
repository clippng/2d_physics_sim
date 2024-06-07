cmake_minimum_required(VERSION 3.10)

add_library(world STATIC camera.cpp event.cpp world_generation.cpp world.cpp global.cpp)

target_include_directories(world PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(world PUBLIC tools renderer elements)

