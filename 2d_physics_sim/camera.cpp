#include "camera.hpp"
#include "math.h"

#include <iostream>

Camera::Camera(CameraInitInfo* init_info) :  
	width(init_info->unit_utilities_ptr->getCameraWidth()),
	height(init_info->unit_utilities_ptr->getCameraHeight()),
	max_x(init_info->unit_utilities_ptr->getWorldWidth() - init_info->unit_utilities_ptr->getCameraWidth()),
	max_y(init_info->unit_utilities_ptr->getWorldHeight() - init_info->unit_utilities_ptr->getCameraHeight()) {
	framebuffer = init_info->framebuffer_ptr;
	world_data = init_info->world_data_ptr;
	unit_utilities = init_info->unit_utilities_ptr;
	pos_x = init_info->pos_x;
	pos_y = init_info->pos_y;	
	std::cout << max_x << " " << max_y << std::endl;
}


Camera::~Camera() {
	
}

void Camera::moveCamera(float offset_x, float offset_y) {
	pos_x += offset_x;
	pos_y += offset_y;
	if (pos_x < 0.0f) { pos_x = 0.0f; } else if (pos_x > max_x) { pos_x = max_x; }
	if (pos_y < 0.0f) { pos_y = 0.0f; } else if (pos_y > max_y) { pos_y = max_y; }
}

void Camera::updateCamera() {
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
	if (pos_x < 0.0f) { pos_x = 0.0f; } else if (pos_x > max_x) { pos_x = max_x; }
	if (pos_y < 0.0f) { pos_y = 0.0f; } else if (pos_y > max_y) { pos_y = max_y; }
	pos_x = floor(pos_x);
	pos_y = floor(pos_y);
	for (uint32_t row = pos_y, local_row = 0, i = 0; row < pos_y + unit_utilities->getCameraHeight(); ++row, ++local_row) {
		for (uint32_t column = pos_x, local_column = 0; column < pos_x + unit_utilities->getCameraWidth(); ++column, ++local_column, ++i) {
			// should use current map                                      
			framebuffer->writeTo(unit_utilities->getBufferIndex(local_row, local_column), colour_map.at(world_data->at(i)));
		}
	}
}