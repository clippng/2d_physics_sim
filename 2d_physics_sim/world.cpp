
#include "world.hpp"
#include "world_generation.hpp"

#include <iostream>

World::World(const WorldInitInfo* init_info) :
	width(init_info->unit_utilities_ptr->getWorldWidth()), 
	height(init_info->unit_utilities_ptr->getWorldHeight()),
	size(init_info->unit_utilities_ptr->getWorldSize()) {
		
	unit_utilities = init_info->unit_utilities_ptr;

	generate();

	CameraInitInfo camera_info {
		.unit_utilities_ptr = init_info->unit_utilities_ptr,
		.framebuffer_ptr = init_info->framebuffer_ptr,
		.world_data_ptr = world_data,
		.pos_x = 0,
		.pos_y = 0
	};

	camera = std::shared_ptr<Camera>(new Camera(&camera_info));
}

World::~World() {

}

void World::generate() {
	srand(time(nullptr));
	world_data = WorldGenerationTools::generateWorld(rand(), width, height);
}

void World::update() {
	// for (auto row = 0; row < width; ++row) {
	// 	for (auto column = 0; column < height; ++column) {
	// 		// check if needs update
	// 			// update 
	// 	}
	// }
	camera->updateCamera();
}

void World::updateCurrentBlockMap() {

}