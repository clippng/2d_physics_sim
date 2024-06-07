#pragma once

#include "utils.hpp"

enum BlockType {
	NONE = 0,
	DIRT = 1,
	SAND = 2,
	STONE = 3,
	WATER = 4
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

class Water : public Liquid {
public:
	Water();

	inline uint32_t getColour() const override { return 0x0000FFFF; }
};