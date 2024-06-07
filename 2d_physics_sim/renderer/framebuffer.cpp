#include "framebuffer.hpp"

Framebuffer::Framebuffer(std::shared_ptr<GlobalConstants> unit_utilities_ptr) {
	unit_utilities = unit_utilities_ptr;
	Colour default_colour = { .red=255, .green=0, .blue=0, .alpha=255 };
	data = std::unique_ptr<std::vector<uint32_t>>(new std::vector<uint32_t>(unit_utilities->getCameraSize(), default_colour.data()));
	size = unit_utilities->getCameraSize();
	row_byte_size = unit_utilities->getCameraWidth() * sizeof(uint32_t);
}

Framebuffer::~Framebuffer() {

}

uint32_t Framebuffer::getSize() {
	return size;
}

int Framebuffer::getRowSize() {
	return row_byte_size;
}

void Framebuffer::writeTo(const uint32_t index, const uint32_t colour) {
	data->at(index) = colour;
}

void* Framebuffer::readFrom() {
	return (void*)data->data();
}