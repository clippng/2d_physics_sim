#include <SDL2/SDL.h>
#include <glm/glm.hpp>

#include "display.hpp"
#include "world.hpp"
#include "event.hpp"
#include "clock.hpp"

// maybe jsut use a global state machine instead of random references everywhere
// https://www.youtube.com/watch?v=u8wrPlpeO5A

// finish proof of concept then rewrite with vulkan possibly?

//#include <iostream>
// world object is self contained and only communicates to the display object by writing pixels to the framebuffer
// that is shared between them. unit utilities is a sort of global namespace for unit constants and tools for conversion

// yea ive decieded this project might be beyond saving the structure is just so bad -- will probably port it to opengl or 
// vulkan soon
int main() {
	const GlobalConstantsInitInfo unit_info {
		.pixel_size = 4,		
		.window_width = 800,
		.window_height = 800,
		.world_width = 200,
		.world_height = 200,
	};

	std::shared_ptr<GlobalConstants> global_constants(new GlobalConstants(&unit_info));
	std::shared_ptr<Framebuffer>framebuffer(new Framebuffer(global_constants));

	const WorldInitInfo world_info {
		.unit_utilities_ptr = global_constants,
		.framebuffer_ptr = framebuffer,
		.camera_pos_x = 0,
		.camera_pos_y = 0,
	};

	std::unique_ptr<World> world(new World(&world_info));
	std::unique_ptr<Display> display(new Display(framebuffer, global_constants));

	const EventInitInfo event_info {
		.camera = world->getCamera()
	};

	std::shared_ptr<Event> event_handler(new Event(&event_info));

	std::unique_ptr<Clock> clock(new Clock(100));

	while (!event_handler->shouldClose()) {
		clock->startTick();
		event_handler->pollEvents();
		if (clock->needsUpdate()) {
			world->update();
			display->update();
			clock->endTick();
		}
	}	

	return EXIT_SUCCESS;
}