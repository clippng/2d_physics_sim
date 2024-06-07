
#include "world.hpp"
#include "world_generation.hpp"
#include "global.cpp"

// #include <iostream>

World::World() :
	width(global.world_width), 
	height(global.world_width),
	size(global.world_size) {

	generate();

	camera = std::shared_ptr<Camera>(new Camera(world_data));
}

World::~World() {

}

void World::generate() {
	srand(time(nullptr));
	world_data = WorldGenerationTools::generateWorld(rand(), width, height);
}

void World::update() {
	// sand physics
	for (auto row = height - 2; row != -1; --row) {
		for (auto column = 0; column < width; ++column) {
			const uint32_t index = row * width + column;
			if (world_data->at(index) != NONE) {
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
			}
		}
	}
	camera->updateCamera();
}

void World::moveCamera(float offset_x, float offset_y) {
	camera->moveCamera(offset_x, offset_y);
}