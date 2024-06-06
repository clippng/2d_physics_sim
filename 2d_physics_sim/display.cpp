#include "display.hpp"

#include <iostream>


Display::Display(std::shared_ptr<Framebuffer> framebuffer_ptr, std::shared_ptr<UnitUtilities> unit_utilities_ptr) { 
	framebuffer = framebuffer_ptr;
	unit_utilities = unit_utilities_ptr;
	
	try {
		SDL_Init(SDL_INIT_EVERYTHING);

		window = SDL_CreateWindow(
			window_title, 
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
			unit_utilities->getWindowWidth(), unit_utilities->getWindowHeight(), 
			window_flags
			);
		renderer = SDL_CreateRenderer(
			window, 
			-1, 
			renderer_flags
			);
		texture = SDL_CreateTexture(
			renderer, 
			SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, 
			unit_utilities->getCameraWidth(), unit_utilities->getCameraHeight()
			);

		if (window == NULL || renderer == NULL || texture == NULL) {
			throw std::runtime_error("SDL failed to initialise");
		}
	} catch (std::runtime_error error) {
		std::cout << error.what() << std::endl;
		exit(1);
	}
}

Display::~Display() {
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
}

bool Display::running() {
	return open;
}

void Display::update() {
	drawFrame();
}

void Display::drawFrame() {
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
	SDL_UpdateTexture(texture, NULL, framebuffer->readFrom(), framebuffer->getRowSize());
	SDL_RenderCopy(renderer, texture, NULL, NULL);  		
	SDL_RenderPresent(renderer);
}