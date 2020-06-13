#include <SDL2/SDL.h>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	const int SCREEN_WIDTH = 640, SCREEN_HEIGHT = 480;
	const std::string SCREEN_TITLE = "Colliders";
	SDL_Event event;
	SDL_Window* window = SDL_CreateWindow(SCREEN_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	bool isRunning = true;

	while (isRunning) {
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT)
			isRunning = false;

		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	return 0;
}