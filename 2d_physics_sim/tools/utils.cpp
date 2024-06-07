#include "utils.hpp"

GlobalConstants::GlobalConstants(const GlobalConstantsInitInfo* init_info) : 
	pixel_size(init_info->pixel_size),
	window_width(init_info->window_width), 
	window_height(init_info->window_height),
	window_size(window_width * window_height),
	world_width(init_info->world_width),
	world_height(init_info->world_height),
	world_size(world_height * world_width), 
	camera_width(window_width / pixel_size),
	camera_height(window_height / pixel_size),
	camera_size(camera_width * camera_height) {};


GlobalConstants::~GlobalConstants() {
	
}