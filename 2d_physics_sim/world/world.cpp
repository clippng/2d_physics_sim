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
	// physics update
	// sand works fine water works okay it will continutally loop unless it can perfectly fit into a row
	for (auto row = height - 2; row != -1; --row) {
		for (auto column = 0; column < width; ++column) {
			const uint32_t index = row * width + column;
			if (world_data->at(index) != NONE) {
				if (world_data->at(index) == SAND) {
					if (world_data->at(index + width) == NONE) {
						world_data->at(index + width) = world_data->at(index);
						world_data->at(index) = NONE;					
					} else if (column > 0 && column < width - 1) {
						if (world_data->at(index - 1 + width) == NONE ) {
							world_data->at(index - 1 + width) = world_data->at(index);
							world_data->at(index) = NONE; 
						} else if (index + width + 1 < width * height) {
							if (world_data->at(index + 1 + width) == NONE) {
								world_data->at(index + 1 + width) = world_data->at(index);
								world_data->at(index) = NONE;
							}
						}
					}
				} else if (world_data->at(index) == WATER) {
					if (world_data->at(index + width) == NONE) {
						world_data->at(index + width) = world_data->at(index);
						world_data->at(index) = NONE;					
					} else if (world_data->at(index - 1 + width) == NONE ) {
						world_data->at(index - 1 + width) = world_data->at(index);
						world_data->at(index) = NONE; 
					} else if (index + width + 1 >= width * height) {
						/** 
						* extra logic incase we cant pass the out of range check
						* only called once if there is a non NONE pixel in the last
						* index position
						*/ 
						if (world_data->at(index - 1) == NONE) {
							world_data->at(index - 1) = world_data->at(index);
							world_data->at(index) = NONE;							
						} else if (world_data->at(index + 1) == NONE) {
							world_data->at(index + 1) = world_data->at(index);
							world_data->at(index) = NONE;
						}
					} else if (world_data->at(index + 1 + width) == NONE) {
						world_data->at(index + 1 + width) = world_data->at(index);
						world_data->at(index) = NONE;
					} else if (world_data->at(index + 1) == NONE) {
						world_data->at(index + 1) = world_data->at(index);
						world_data->at(index) = NONE;							
					} else if (world_data->at(index - 1) == NONE) {
						world_data->at(index - 1) = world_data->at(index);
						world_data->at(index) = NONE;
					}
				}
			}
		}
	}
	camera->updateCamera();
}

void World::moveCamera(float offset_x, float offset_y) {
	camera->moveCamera(offset_x, offset_y);
}