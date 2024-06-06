#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "utils.hpp"
#include "framebuffer.hpp"

#include <memory>

class Display {
public:
	Display(std::shared_ptr<Framebuffer> framebuffer_ptr, std::shared_ptr<UnitUtilities> unit_utilities_ptr);
	~Display();

	bool running();

	void update();

private:
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Window* window;	

	std::shared_ptr<UnitUtilities> unit_utilities;
	std::shared_ptr<Framebuffer> framebuffer;

	const SDL_WindowFlags window_flags = SDL_WINDOW_SHOWN;
	const char* window_title = "<Physics Sim>";
	const SDL_RendererFlags renderer_flags = SDL_RENDERER_PRESENTVSYNC;

	Colour default_colour = { .red=10, .green=144, .blue=110, .alpha=255 };
	uint32_t default_colour_data = default_colour.data();

	bool open = true;

	void drawFrame();
};