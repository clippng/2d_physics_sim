#pragma once

#include <deque>

#include "framebuffer.hpp"
#include "block.hpp"
#include <map>

//camera should work per pixel


class Camera {
public:
	Camera(std::shared_ptr<std::vector<BlockType>> world_data_ptr);
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

	Framebuffer *framebuffer;

	// colour lookup array indexed by enum value of blocktype
	const uint32_t colours[5] = { 0x18191AFF, 0x665439FF, 0xBFBE75FF, 0x4D4E52FF, 0x4574D180 };
};