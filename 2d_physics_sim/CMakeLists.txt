cmake_minimum_required(VERSION 3.10)

add_executable(
	2DPhysicsSim

	main.cpp

	display.cpp
	world.cpp
	world_generation.cpp
	block.cpp
	utils.cpp
	framebuffer.cpp
	camera.cpp
	event.cpp
)

target_link_libraries(2DPhysicsSim SDL2)

