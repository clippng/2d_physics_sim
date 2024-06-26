#pragma once

#include <deque>

#include "framebuffer.hpp"
#include "block.hpp"


//camera should work per pixel

struct CameraInitInfo {
	std::shared_ptr<GlobalConstants> unit_utilities_ptr;
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
	void clampCamera();

	const uint32_t width, height;

	const float max_x, max_y;

	float pos_x, pos_y, prev_pos_x, prev_pos_y;

	std::shared_ptr<std::vector<BlockType>> world_data;

	std::unique_ptr<std::deque<std::deque<uint32_t>>> pixel_data; // might be useless

	std::shared_ptr<GlobalConstants> unit_utilities;

	std::shared_ptr<Framebuffer> framebuffer;

	// colour lookup array indexed by enum value of blocktype
	const uint32_t colours[5] = { 0x18191AFF, 0x665439FF, 0xBFBE75FF, 0x4D4E52FF, 0x4574D180 };
};