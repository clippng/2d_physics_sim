#include <GL/glew.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <glm/glm.hpp>

int main() {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow(
		"Test",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800, 800, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
	);

	if (glewInit() != GLEW_OK) {
		
	}
	

	SDL_Quit();

	return 0;
}