#pragma once

#include <cstdint>
#include <chrono>

class Clock {
public:
	Clock(const int tick_length);

	static inline std::chrono::milliseconds getTime() { return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()); }

	void startTick();

	void endTick(); // wait for all operations to complete and then wait the remaining time

	bool needsUpdate();

private:
	const std::chrono::milliseconds TICK_LENGTH;
	uint64_t ticks;

	std::chrono::milliseconds last_tick;

	bool needs_update;
};