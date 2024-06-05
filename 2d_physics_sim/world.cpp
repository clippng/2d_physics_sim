
#include "world.hpp"
#include "world_generation.hpp"

#include <iostream>

World::World(std::unique_ptr<Camera> camera_ptr, std::shared_ptr<UnitUtilities> unit_utilities_ptr) :
	width(unit_utilities_ptr->getWorldWidth()), 
	height(unit_utilities_ptr->getWorldHeight()),
	size(unit_utilities_ptr->getWorldSize()) {

	camera = std::move(camera_ptr);
		
	unit_utilities = unit_utilities_ptr;

	generate();
}

World::~World() {

}

void World::generate() {
	block_map = std::unique_ptr<std::vector<std::vector<std::shared_ptr<Block>>>>(new std::vector<std::vector<std::shared_ptr<Block>>>(height));
	for (uint32_t row = 0; row < height; ++row) {
		block_map->at(row).resize(width);
		for (uint32_t column = 0; column < width; ++column) {
			float noise = WorldGenerationTools::getNoise(
				WorldGenerationTools::map(row, height, 0, 1, 0), 
				WorldGenerationTools::map(column, width, 0, 1, 0));
			std::shared_ptr<Block> block;
			if (noise > 0.5f) { 
				block = std::shared_ptr<Block>(new Dirt());
			} else if (noise < 0.2f) {
				block = std::shared_ptr<Block>(new Stone());
			} else {
				block = std::shared_ptr<Block>(new Sand());
			}
			block_map->at(row).at(column) = block;
		}
	}
	current_block_map = std::unique_ptr<std::deque<std::deque<std::shared_ptr<Block>>>>(new std::deque<std::deque<std::shared_ptr<Block>>>());
	current_block_map->resize(unit_utilities->getGridHeight());
	for (uint32_t i = 0; i < current_block_map->size(); ++i) {
		current_block_map->at(i).resize(unit_utilities->getGridWidth());
	}

}

void World::update() {
	for (auto row = 0; row < width; ++row) {
		for (auto column = 0; column < height; ++column) {
			// check if needs update
				// update 
		}
	}
	camera->updateCamera();
}

void World::updateCurrentBlockMap() {

}