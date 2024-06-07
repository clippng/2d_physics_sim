#include "global.cpp"
#include "event.hpp"

Event::Event() {
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
						global.world->moveCamera(-2, 0);
						break;
					case SDLK_s:
						global.world->moveCamera(0, 2);
						break;
					case SDLK_d:
						global.world->moveCamera(2, 0);
						break;
					case SDLK_w:
						global.world->moveCamera(0, -2);
						break;	
					case SDLK_r:
						global.world->generate();
						break;	
				} 
				break;

			case SDL_QUIT:
				running = false;		
		}		break;
	}
}
