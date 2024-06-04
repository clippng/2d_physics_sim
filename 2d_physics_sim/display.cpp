#include "display.hpp"

#include <iostream>


Display::Display() { // should be initialised with starting window size
	try {
		SDL_Init(SDL_INIT_EVERYTHING);
		window = SDL_CreateWindow(window_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, window_flags);
		renderer = SDL_CreateRenderer(window, 0, renderer_flags);
		texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, grid_width, grid_height);
		unit_utilities = std::shared_ptr<UnitUtilities>(new UnitUtilities(width, height, block_size));
		framebuffer = std::shared_ptr<Framebuffer>(new Framebuffer(unit_utilities));
		if (window == NULL || renderer == NULL || texture == NULL) {
			throw std::runtime_error("SDL failed to initialise");
		}
	} catch (std::runtime_error error) {
		std::cout << error.what() << std::endl;
		exit(1);
	}

}

Display::~Display() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
}

bool Display::running() {
	return open;
}

void Display::update() {
	pollEvents();
	drawFrame();
}

void Display::pollEvents() {
	while (SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym) {
					case SDLK_ESCAPE:
						std::cout << "escape";
						open = false;	
				}
			case SDL_QUIT:
				open = false;		
		}		
	}
}

void Display::drawFrame() {
	SDL_UpdateTexture(texture, NULL, framebuffer.get(), grid_width * sizeof(uint32_t));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);  		
	SDL_RenderPresent(renderer);
}