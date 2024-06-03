cmake_minimum_required(VERSION 3.10)

add_executable(
	2DPhysicsSim

	glad.c

	main.cpp
)

target_link_libraries(2DPhysicsSim SDL2)
target_link_libraries(2DPhysicsSim OpenGL)

