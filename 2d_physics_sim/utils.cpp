#include "utils.hpp"

UnitUtilities::UnitUtilities(const UnitUtilitiesInitInfo* init_info) : 
	window_width(init_info->window_width), 
	window_height(init_info->window_height),
	block_size(init_info->block_size),
	world_width(init_info->world_width),
	world_height(init_info->window_height), 
	grid_width(window_width / block_size),
	grid_height(window_height / block_size),
	grid_size(grid_width * grid_height),
	world_size(world_height * world_width) {};


UnitUtilities::~UnitUtilities() {
	
}