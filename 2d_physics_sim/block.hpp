#pragma once

enum class BlockID {
	NONE = 0,
	STONE = 1
};

class Block {
public:
	Block();
	~Block();

protected:
	const BlockID id = BlockID::NONE;

	float pos_x, pos_y; // maybe should be int

	float density;

	float hardness;



};