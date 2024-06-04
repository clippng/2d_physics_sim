#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

#include "world.hpp"

#include "utils.hpp"
#include "framebuffer.hpp"

#include <iostream>
#include <vector>
#include <memory>

class Display {
public:
	Display();
	~Display();

	bool running();

	void update();

private:
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Window* window;	
	SDL_Event event;

	static const uint32_t width = 800; // need to deciede if window can be resized or not
	static const uint32_t height = 800;
	static const uint32_t block_size = 100; // size of a 'pixel'
	static const uint32_t grid_width = width / block_size;
	static const uint32_t grid_height = height / block_size;
	static const uint32_t grid_size = grid_width * grid_height;

	const SDL_WindowFlags window_flags = SDL_WINDOW_SHOWN;
	const char* window_title = "<Physics Sim>";
	const SDL_RendererFlags renderer_flags = SDL_RENDERER_PRESENTVSYNC;

	std::shared_ptr<UnitUtilities> unit_utilities;
	std::shared_ptr<Framebuffer> framebuffer;

	World* world;

	bool open = true;

	void pollEvents();	

	void drawFrame();
};