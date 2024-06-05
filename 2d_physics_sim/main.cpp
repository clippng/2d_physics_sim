#include <SDL2/SDL.h>
#include <glm/glm.hpp>

#include "display.hpp"
#include "world.hpp"

// world object is self contained and only communicates to the display object by writing pixels to the framebuffer
// that is shared between them. unit utilities is a sort of global namespace for unit constants and tools for conversion

// need to fix how world space is treated -- its unclear if its per pixel or per block
int main() {
	const UnitUtilitiesInitInfo unit_info {
		.window_width = 800,
		.window_height = 800,
		.block_size = 4,
		.world_width = 1000,
		.world_height = 400
	};

	std::shared_ptr<UnitUtilities> unit_utilities(new UnitUtilities(&unit_info));
	std::shared_ptr<Framebuffer>framebuffer(new Framebuffer(unit_utilities));

	const CameraInitInfo camera_info {
		.framebuffer_ptr = framebuffer,
		.pos_x=0,
		.pos_y=0,
		.width=800,
		.height=800
	};
	
	std::unique_ptr<World> world(new World(std::unique_ptr<Camera>(new Camera(&camera_info)), unit_utilities));
	std::unique_ptr<Display> display(new Display(framebuffer, unit_utilities));

	while (display->running()) {
		world->update();
		display->update();
	}	

	return EXIT_SUCCESS;
}