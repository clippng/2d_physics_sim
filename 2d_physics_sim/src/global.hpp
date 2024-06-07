#pragma once

#include "framebuffer.hpp"
#include "world.hpp"
#include "display.hpp"
#include "clock.hpp"

struct Global {	
	// global objects variables state
	Framebuffer *framebuffer;
	Display *display;
	World *world;
	Event *event_handler;
	Clock *clock;

	const uint32_t pixel_size = 4; // size of pixel ie how many real pixels make up one side of a surface pixel
	const uint32_t window_width = 800; 
	const uint32_t window_height = 800;
	const uint32_t world_width = 200;
	const uint32_t world_height = 200;
	const uint32_t camera_width = 200;
	const uint32_t camera_height = 200;
	const uint32_t world_size = world_height * world_width;
	const uint32_t window_size = window_height * window_width;
	const uint32_t camera_size = camera_height * camera_width;
	const std::chrono::milliseconds tick_length = std::chrono::milliseconds(100);
};	
