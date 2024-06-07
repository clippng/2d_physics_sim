#include "clock.hpp"
#include <iostream>

Clock::Clock(const int tick_rate) : TICK_LENGTH(std::chrono::milliseconds(tick_rate)) {
	
}

void Clock::startTick() {
	if (getTime() - last_tick > TICK_LENGTH) {
		needs_update = true;
	}
}

void Clock::endTick() {
	std::chrono::milliseconds previous_tick_length = getTime() - last_tick;
	// std::this_thread::sleep_for(TICK_LENGTH - previous_tick_length);
	std::cout << "previous tick length " << previous_tick_length << std::endl;
	last_tick = getTime();
	
	needs_update = false;
}

bool Clock::needsUpdate() {
	return needs_update;
}