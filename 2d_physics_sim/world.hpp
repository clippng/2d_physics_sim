#pragma once

#include <deque>
#include <vector>
#include <memory>

#include "block.hpp"
#include "camera.hpp"


class World {
public:
	World(std::unique_ptr<Camera> camera, std::shared_ptr<UnitUtilities> unit_utilities_ptr);
	~World();
	void generate();

	void update(); // update the physics for each block

private:
	const int64_t world_seed = -2123123487344076345;
	const double normalised_world_seed = static_cast<double>(INT64_MAX / world_seed);

	const uint32_t width, height, size; 

	// block pointers can be shared between map and current map but should only be written to by map
	std::unique_ptr<std::vector<std::vector<std::shared_ptr<Block>>>> block_map; // 2D vector that stores block data for the whole world

	std::unique_ptr<std::deque<std::deque<std::shared_ptr<Block>>>> current_block_map; // 2D deque that contains currently visible block data -- essesntially a portion of block_map

	std::unique_ptr<Camera> camera;

	std::shared_ptr<UnitUtilities> unit_utilities;

	void updateCurrentBlockMap();
};