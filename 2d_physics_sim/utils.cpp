#include "utils.hpp"

UnitUtilities::UnitUtilities(const uint32_t window_width, const uint32_t window_height, const uint32_t block_size) {
	this->window_width = window_width;
	this->window_height = window_height;
	this->block_size = block_size;
	grid_width = window_width / block_size;
	grid_height = window_height / block_size;
	grid_size = grid_width * grid_height;
}