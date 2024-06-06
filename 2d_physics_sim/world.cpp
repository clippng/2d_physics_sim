
#include "world.hpp"
#include "world_generation.hpp"

#include <iostream>

World::World(const WorldInitInfo* init_info) :
	width(init_info->unit_utilities_ptr->getWorldWidth()), 
	height(init_info->unit_utilities_ptr->getWorldHeight()),
	size(init_info->unit_utilities_ptr->getWorldSize()) {

	world_data = std::shared_ptr<std::vector<BlockType>>(new std::vector<BlockType>(size, BlockType::NONE));
		
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
	world_data = std::shared_ptr<std::vector<BlockType>>(new std::vector<BlockType>(size));
	for (uint32_t i = 0, row = 0; row < height; ++row) {
		for (uint32_t column = 0; column < width; ++column, ++i) {
			float noise = WorldGenerationTools::getNoise(row, column);
			BlockType block;

			if (noise > 0.5f) { 
				block = BlockType::DIRT;
			} else if (noise < 0.2f) {
				block = BlockType::STONE;
			} else {
				block = BlockType::SAND;
			}
			world_data->at(i) = block;
		}
	}
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