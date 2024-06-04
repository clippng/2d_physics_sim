#include <SDL2/SDL.h>
#include <glm/glm.hpp>

#include "display.hpp"

int main() {
	Display display;

	while (display.running()) {
		display.update();
	}
	

	return EXIT_SUCCESS;
}