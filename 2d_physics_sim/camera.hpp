#pragma once

#include <deque>

#include "framebuffer.hpp"
#include "block.hpp"
#include <map>

//camera should work per pixel

struct CameraInitInfo {
	std::shared_ptr<UnitUtilities> unit_utilities_ptr;
	std::shared_ptr<Framebuffer> framebuffer_ptr;
	std::shared_ptr<std::vector<BlockType>> world_data_ptr;
	float pos_x;
	float pos_y;
};

class Camera {
public:
	Camera(CameraInitInfo* init_info);
	~Camera();

	void moveCamera(float pos_x, float pos_y);

	void updateCamera();

	void writeToFrameBuffer();

private:
	const uint32_t width, height;

	const float max_x, max_y;

	float pos_x, pos_y, prev_pos_x, prev_pos_y;

	std::shared_ptr<std::vector<BlockType>> world_data;

	std::unique_ptr<std::deque<std::deque<uint32_t>>> pixel_data; // might be useless

	std::shared_ptr<UnitUtilities> unit_utilities;

	std::shared_ptr<Framebuffer> framebuffer;

	const std::map<BlockType, uint32_t> colour_map = { 
		{ BlockType::NONE, 0x00000000 }, 
		{ BlockType::DIRT, 0x665439FF }, 
		{ BlockType::SAND, 0xBFBE75FF },
		{ BlockType::STONE, 0x4D4E52FF } 
	};
};