#include "event.hpp"

Event::Event(const EventInitInfo* init_info) {
	world = init_info->world_ptr;
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
						world->moveCamera(-2, 0);
						break;
					case SDLK_s:
						world->moveCamera(0, 2);
						break;
					case SDLK_d:
						world->moveCamera(2, 0);
						break;
					case SDLK_w:
						world->moveCamera(0, -2);
						break;	
					case SDLK_r:
						world->generate();
						break;	
				} 
				break;

			case SDL_QUIT:
				running = false;		
		}		break;
	}
}