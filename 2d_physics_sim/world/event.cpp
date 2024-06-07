
#include "event.hpp"

Event::Event(const EventInitInfo* init_info) {
	camera = init_info->camera;
	running = true;
}

Event::~Event() {

}


void Event::pollEvents() {
	while (SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym) {
					case SDLK_ESCAPE:
						running = false;
						break;	
					case SDLK_a:
						camera->moveCamera(-2, 0);
						break;
					case SDLK_s:
						camera->moveCamera(0, 2);
						break;
					case SDLK_d:
						camera->moveCamera(2, 0);
						break;
					case SDLK_w:
						camera->moveCamera(0, -2);
						break;	
					case SDLK_r:
						// new world
						break;	
				} 
				break;

			case SDL_QUIT:
				running = false;		
		}		break;
	}
}
