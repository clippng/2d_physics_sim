#pragma once

#include <deque>

#include "block.hpp"

class World {
public:
	World();
	~World();

private:
	std::deque<std::deque<Block>>* block_map;

};