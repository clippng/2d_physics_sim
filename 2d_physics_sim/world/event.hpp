#pragma once

#include <SDL2/SDL_events.h>

#include "world.hpp"

struct EventInitInfo {
	std::shared_ptr<World> world_ptr;
};

class Event {
public:
	Event(const EventInitInfo* init_info);
	~Event();
	inline bool shouldClose() { return !running; };

	void pollEvents();

private:
	SDL_Event event;

	std::shared_ptr<World> world; 

	bool running;
};