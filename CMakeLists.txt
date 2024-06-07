cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(2DPhysicsSim)

add_subdirectory(2d_physics_sim)

find_package(SDL2 REQUIRED)




