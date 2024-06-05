#include "camera.hpp"


Camera::Camera(const CameraInitInfo* init_info) {
	unit_utilities = init_info->unit_utilities;
	framebuffer = init_info->framebuffer_ptr;
	pos_x = init_info->pos_x;
	pos_y = init_info->pos_y;
	width = init_info->width;
	height = init_info->height;
}

Camera::~Camera() {
	
}

void Camera::moveCamera(float pos_x, float pos_y) {
	this->pos_x = pos_x;
	this->pos_y = pos_y;
	updateCamera();
}

void Camera::updateCamera() {
	if (prev_pos_x != pos_x || prev_pos_y != pos_y) {
		float change_x = pos_x - prev_pos_x;
		float change_y = pos_y - prev_pos_y;
	} 

	prev_pos_x = pos_x;
	prev_pos_y = pos_y;
}

void Camera::writeToFrameBuffer() {
	for (auto row = 0; row < width; ++row) {
		for (auto column = 0; column < height; ++column) {
			// should use current map
			framebuffer->writeTo(unit_utilities->getGridIndex(row, column), data->at(row).at(column)->getColour());
		}
	}
}