#include "framebuffer.hpp"

#include "global.cpp"
#include "utils.hpp"

Framebuffer::Framebuffer() {
	Colour default_colour = { .red=255, .green=0, .blue=0, .alpha=255 };
	data = std::unique_ptr<std::vector<uint32_t>>(new std::vector<uint32_t>(global.camera_size, default_colour.data()));
	size = global.camera_size;
	row_byte_size = global.camera_width * sizeof(uint32_t);
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

