#pragma once

#include "utils.hpp"

enum class BlockType {
	NONE = 0,
	STONE = 1,
	SAND = 2,
	DIRT = 3
};

// need to have a way to list interactions between blocks

class Block {
public:
	virtual uint32_t getColour() const = 0;

protected:
	Colour colour;

	uint32_t colour_data;

	BlockType id;

	float density;
};

class Solid : public Block {

protected:
	bool gravity_effected; 

	float hardness;
};

class Liquid : public Block {
	bool viscosity;


};

class Gas : public Block {

};

class Custom : public Block {
public:
	Custom(uint32_t colour);

	inline uint32_t getColour() const override { return colour_data; }
};

class Air : public Gas {
public:
	Air();

	inline uint32_t getColour() const override { return 0x00000000; }
};

class Stone : public Solid {
public:
	Stone();

	inline uint32_t getColour() const override { return 0x4D4E52FF; }
};

class Sand : public Solid {
public: 
	Sand();

	inline uint32_t getColour() const override { return 0xBFBE75FF; }
};

class Dirt : public Solid {
public:
	Dirt();

	inline uint32_t getColour() const override { return 0x665439FF; }
};