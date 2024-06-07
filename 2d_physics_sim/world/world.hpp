#pragma once

#include <deque>
#include <vector>
#include <memory>

#include "block.hpp"
#include "camera.hpp"
#include "event.hpp"

struct WorldInitInfo {
	std::shared_ptr<UnitUtilities> unit_utilities_ptr;
	std::shared_ptr<Framebuffer> framebuffer_ptr;
	float camera_pos_x;
	float camera_pos_y;
};


class World {
public:
	World(const WorldInitInfo* init_info);
	~World();
	void generate();

	void update(); // update the physics for each block

	inline std::shared_ptr<Camera> getCamera() { return camera; }

private:
	const int64_t world_seed = -2123123487324076345;
	const double normalised_world_seed = static_cast<double>(INT64_MAX / world_seed);

	const uint32_t width, height, size; 

	// block pointers can be shared between map and current map but should only be written to by map
	//std::shared_ptr<std::vector<std::vector<Block>>> world_data; // 2D vector that stores block data for the whole world
	std::shared_ptr<std::vector<BlockType>> world_data;

	std::shared_ptr<Camera> camera;

	std::shared_ptr<UnitUtilities> unit_utilities;

	void updateCurrentBlockMap();
};