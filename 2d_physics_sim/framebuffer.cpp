#include "framebuffer.hpp"

Framebuffer::Framebuffer(std::shared_ptr<UnitUtilities> unit_utilities) {
	this->unit_utilities = unit_utilities;
	Colour default_colour = { .red=0, .green=0, .blue=0, .alpha=255 };
	data = new std::vector<uint32_t>(this->unit_utilities->getGridSize(), default_colour.getColour());
}

Framebuffer::~Framebuffer() {
	delete data;
}

void Framebuffer::writeToFramebuffer(const uint32_t index, const uint32_t colour) {
	data->at(index) = colour;
}

