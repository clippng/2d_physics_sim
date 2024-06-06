#include <SDL2/SDL.h>
#include <glm/glm.hpp>

#include "display.hpp"
#include "world.hpp"
#include "event.hpp"

#include <iostream>
// world object is self contained and only communicates to the display object by writing pixels to the framebuffer
// that is shared between them. unit utilities is a sort of global namespace for unit constants and tools for conversion

// need to fix how world space is treated -- its unclear if its per pixel or per block
int main() {
	const UnitUtilitiesInitInfo unit_info {
		.pixel_size = 2,		
		.window_width = 800,
		.window_height = 800,
		.world_width = 800,
		.world_height = 600,
	};

	std::shared_ptr<UnitUtilities> unit_utilities(new UnitUtilities(&unit_info));
	std::shared_ptr<Framebuffer>framebuffer(new Framebuffer(unit_utilities));

	const WorldInitInfo world_info {
		.unit_utilities_ptr = unit_utilities,
		.framebuffer_ptr = framebuffer,
		.camera_pos_x = 100,
		.camera_pos_y = 100,
	};

	std::unique_ptr<World> world(new World(&world_info));
	std::unique_ptr<Display> display(new Display(framebuffer, unit_utilities));

	const EventInitInfo event_info {
		.camera = world->getCamera()
	};

	std::shared_ptr<Event> event_handler(new Event(&event_info));

	while (!event_handler->shouldClose()) {
		event_handler->pollEvents();
		world->update();
		display->update();
	}	

	return EXIT_SUCCESS;
}