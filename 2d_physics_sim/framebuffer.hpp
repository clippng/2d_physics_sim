#pragma once

#include "utils.hpp"

#include <memory>
#include <stdint.h>
#include <vector>
#include <any>

// currently only support 4 channel 32bit colours
class Framebuffer {
public:
	Framebuffer(std::shared_ptr<UnitUtilities> unit_utilities_ptr);
	
	~Framebuffer();

	uint32_t getSize();

	int getRowSize();

	void writeTo(const uint32_t position, const uint32_t colour);

	void* readFrom();

private:
	std::unique_ptr<std::vector<uint32_t>> data; // vector that can be written to

	std::shared_ptr<UnitUtilities> unit_utilities;

	uint32_t size;

	int row_byte_size;
};
