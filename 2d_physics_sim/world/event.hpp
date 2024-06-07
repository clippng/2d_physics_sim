

#pragma once

#include <SDL2/SDL_events.h>

#include "camera.hpp"

class Event {
public:
	Event();
	~Event();
	inline bool shouldClose() { return !running; };

	void pollEvents();

private:
	SDL_Event event;

	bool running;
};