#pragma once

#include <deque>

#include "framebuffer.hpp"
#include "block.hpp"

struct CameraInitInfo {
	std::shared_ptr<UnitUtilities> unit_utilities;
	std::shared_ptr<Framebuffer> framebuffer_ptr;
	float pos_x;
	float pos_y;
	float width;
	float height;
};

class Camera {
public:
	Camera(const CameraInitInfo* init_info);
	~Camera();

	void moveCamera(float pos_x, float pos_y);

	void updateCamera();

	void writeToFrameBuffer();

private:
	float pos_x, pos_y, prev_pos_x, prev_pos_y;
	float width, height;

	// should borrow ptrs from world and add to ends of que
	std::shared_ptr<std::deque<std::deque<std::shared_ptr<Block>>>> data;

	std::shared_ptr<UnitUtilities> unit_utilities;

	std::shared_ptr<Framebuffer> framebuffer;

};