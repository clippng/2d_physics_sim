#pragma once

#include <cstdint>

struct Colour {
	uint8_t red = 0x00;
	uint8_t green = 0x00;
	uint8_t blue = 0x00;
	uint8_t alpha = 0x00;

	uint32_t getColour() {
		uint32_t r = red << 24;
		uint32_t g = green << 16;
		uint32_t b = blue << 8;
		uint32_t a = alpha;
		return (uint32_t) r | g | b | a;
	}
};

// add utilites for access grid as if it were 2D { x , y }
class UnitUtilities {
public:
	UnitUtilities(const uint32_t window_width, const uint32_t window_height, const uint32_t block_size);

	~UnitUtilities();

	inline uint32_t convertToMatrix(uint32_t pixel_index) { return pixel_index / block_size; }

	inline uint32_t convertToScreen(uint32_t grid_index) { return grid_index * block_size; }

	inline uint32_t getWidth() { return window_width; }

	inline uint32_t getHeight() { return window_height; }

	inline uint32_t getGridHeight() { return grid_height; }

	inline uint32_t getGridWidth() { return grid_width; }

	inline uint32_t getGridSize() { return grid_size; }

	inline uint32_t getBlockSize() { return block_size; }
	
private:
	uint32_t window_width; // need to deciede if window can be resized or not
	uint32_t window_height;
	uint32_t block_size; // size of a  block in pixels
	uint32_t grid_width;
	uint32_t grid_height;
	uint32_t grid_size;
};