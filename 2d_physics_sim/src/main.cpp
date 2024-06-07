#include <SDL2/SDL.h>
#include <glm/glm.hpp>

#include "display.hpp"
#include "world.hpp"
#include "event.hpp"
#include "clock.hpp"

#include "global.hpp"

// maybe jsut use a global state machine instead of random references everywhere
// https://www.youtube.com/watch?v=u8wrPlpeO5A

// finish proof of concept then rewrite with vulkan possibly?

// #include <iostream>
// world object is self contained and only communicates to the display object by writing pixels to the framebuffer
// that is shared between them. unit utilities is a sort of global namespace for unit constants and tools for conversion

// need to fix how world space is treated -- its unclear if its per pixel or per block
int main() {
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
	} global;	

	while (!global.event_handler->shouldClose()) {
		global.clock->startTick();
		global.event_handler->pollEvents();
		if (global.clock->needsUpdate()) {
			global.world->update();
			global.display->update();
			global.clock->endTick();
		}
	}	

	return EXIT_SUCCESS;
}