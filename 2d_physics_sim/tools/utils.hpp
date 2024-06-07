#pragma once

#include <cstdint>
#include "global.hpp"

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


// fuck this class
// struct UnitUtilitiesInitInfo {
// 	uint32_t pixel_size;
// 	uint32_t window_width;
// 	uint32_t window_height;
// 	uint32_t world_width;
// 	uint32_t world_height;
// };

// class UnitUtilities {
// public:
// 	UnitUtilities(const UnitUtilitiesInitInfo* init_info);

// 	~UnitUtilities();

// 	inline uint32_t convertToWorldSpace(const uint32_t pixel_index) { return pixel_index / pixel_size; }

// 	inline uint32_t convertToWindowSpace(const uint32_t grid_index) { return grid_index * pixel_size; }

// 	// inline uint32_t getPixelSize() const { return pixel_size; }

// 	// inline uint32_t getWindowWidth() const { return window_width; }

// 	// inline uint32_t getWindowHeight() const { return window_height; }

// 	// inline uint32_t getWindowSize() const { return window_size; }

// 	// inline uint32_t getCameraWidth() const { return camera_width; }

// 	// inline uint32_t getCameraHeight() const { return camera_height; }

// 	// inline uint32_t getCameraSize() const { return camera_size; }

// 	// inline uint32_t getWorldWidth() const { return world_width;  }

// 	// inline uint32_t getWorldHeight() const { return world_height; }

// 	// inline uint32_t getWorldSize() const { return world_size; }

// 	inline uint32_t getBufferIndex(const uint32_t row, uint32_t column) const { return (row * camera_width) + column; }

// 	inline std::array<uint32_t, 2> getCardinalPosition(const uint32_t index) const { return {index / camera_width, index % camera_width}; }
	
// private:
// 	const uint32_t pixel_size; // size of pixel ie how many real pixels make up one side of a surface pixel
// 	const uint32_t window_width; // need to deciede if window can be resized or not
// 	const uint32_t window_height;
// 	const uint32_t window_size; // how many pixels in screen
// 	const uint32_t world_width;
// 	const uint32_t world_height;
// 	const uint32_t world_size;
// 	const uint32_t camera_width;
// 	const uint32_t camera_height;
// 	const uint32_t camera_size;

// 	// the names are super confusing

// 	// window -- the actual physical pixel measurement of the window
// 	// camera / surface / framebuffer -- window / pixel_size
// 	// world -- number of blocks in world -- currently uses same scaling as camera space
// 	// pixel -- in this case a pixel refers to the scaled pixel value
// };