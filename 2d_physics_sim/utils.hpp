#pragma once

#include <cstdint>

struct Colour {
	uint8_t red = 0x00;
	uint8_t green = 0x00;
	uint8_t blue = 0x00;
	uint8_t alpha = 0x00;

	uint32_t data() {
		uint32_t r = red << 24;
		uint32_t g = green << 16;
		uint32_t b = blue << 8;
		uint32_t a = alpha;
		return (uint32_t) r | g | b | a;
	}
};

struct UnitUtilitiesInitInfo {
	uint32_t window_width;
	uint32_t window_height;
	uint32_t block_size;
	uint32_t world_width;
	uint32_t world_height;
};

// add utilites for access grid as if it were 2D { x , y }
class UnitUtilities {
public:
	UnitUtilities(const UnitUtilitiesInitInfo* init_info);

	~UnitUtilities();

	inline uint32_t convertToMatrix(uint32_t pixel_index) { return pixel_index / block_size; }

	inline uint32_t convertToScreen(uint32_t grid_index) { return grid_index * block_size; }

	inline uint32_t getWidth() { return window_width; }

	inline uint32_t getHeight() { return window_height; }

	inline uint32_t getGridHeight() { return grid_height; }

	inline uint32_t getGridWidth() { return grid_width; }

	inline uint32_t getGridSize() { return grid_size; }

	inline uint32_t getBlockSize() { return block_size; }

	inline uint32_t getWorldWidth() { return world_width;  }

	inline uint32_t getWorldHeight() { return world_height; }

	inline uint32_t getWorldSize() { return world_size; }

	inline uint32_t getGridIndex(uint32_t row, uint32_t column) { return (row * grid_width) + column; }
	
private:
	const uint32_t window_width; // need to deciede if window can be resized or not
	const uint32_t window_height;
	const uint32_t block_size; // size of a  block in pixels
	const uint32_t grid_width; // screen space in terms of blocks not pixels
	const uint32_t grid_height;
	const uint32_t grid_size; 
	const uint32_t world_width;
	const uint32_t world_height;
	const uint32_t world_size;
};