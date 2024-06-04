#pragma once

#include "utils.hpp"

#include <memory>
#include <stdint.h>
#include <vector>

class Framebuffer {
public:
	Framebuffer(std::shared_ptr<UnitUtilities> unit_utilities);
	
	~Framebuffer();

	void writeToFramebuffer(const uint32_t position, const uint32_t colour);

private:
	std::vector<uint32_t>* data;

	std::shared_ptr<UnitUtilities> unit_utilities;


};
