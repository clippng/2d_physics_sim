#include "block.hpp"

Custom::Custom(uint32_t colour) {
	colour_data = colour;
}

Air::Air() {
	Colour colour = { .red=0, .green=0, .blue=0, .alpha=0 };
	uint32_t colour_data = colour.data();
	id = BlockType::NONE;
	density = 0.0f;
}

Stone::Stone() {
	Colour colour = { .red=77, .green=78, .blue=82, .alpha=255 };
	uint32_t colour_data = colour.data();
	id = BlockType::STONE;
	density = 1.0f;
	hardness = 1.0f;
}

Sand::Sand() {
	Colour colour = { .red=191, .green=190, .blue=117, .alpha=255 };
	uint32_t colour_data = colour.data();
	id = BlockType::SAND;
	density = 0.3f;
	hardness = 0.2f;
}

Dirt::Dirt() {
	Colour colour = { .red=102, .green=84, .blue=57, .alpha=255 };
	uint32_t colour_data = colour.data();
	id = BlockType::DIRT;
	density = 0.5f;
	hardness = 0.2f;
}