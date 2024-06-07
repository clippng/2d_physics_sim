#include "camera.hpp"
#include "math.h"
#include "global.cpp"

// #include <iostream>

Camera::Camera(std::shared_ptr<std::vector<BlockType>> world_data_ptr) :  
	width(global.camera_width),
	height(global.camera_height),
	max_x(global.world_width - global.camera_width),
	max_y(global.world_height - global.camera_height) {
	framebuffer = global.framebuffer;
	world_data = world_data_ptr;
	pos_x = 0;
	pos_y = 0;
}


Camera::~Camera() {
	
}

void Camera::moveCamera(float offset_x, float offset_y) {
	pos_x += offset_x;
	pos_y += offset_y;
}

void Camera::updateCamera() {
	clampCamera();
	if (prev_pos_x != pos_x || prev_pos_y != pos_y) {
		for (auto row = 0; row < width; ++row) {
			for (auto column = 0; column < height; ++column) {
				// get data from current x -> x + width
				// and current y -> y + height
			}
		}
	}

	prev_pos_x = pos_x;
	prev_pos_y = pos_y;
	writeToFrameBuffer();
}

void Camera::writeToFrameBuffer() {
	clampCamera();
	for (uint32_t row = pos_y, i = 0; row < pos_y + global.camera_height; ++row) {
		for (uint32_t column = pos_x, local_column = 0; column < pos_x + global.camera_width; ++column, ++i) {
			// should use current map        
			                             
			framebuffer->writeTo(i, colours[world_data->at(row * global.world_width + column)]);
		}
	}
}

void Camera::clampCamera() {
	if (pos_x < 0.0f) { pos_x = 0.0f; } else if (pos_x > max_x) { pos_x = max_x; }
	if (pos_y < 0.0f) { pos_y = 0.0f; } else if (pos_y > max_y) { pos_y = max_y; }
	pos_x = floor(pos_x);
	pos_y = floor(pos_y);
}