#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include "Paddle.hpp"
#include "EventHandler.hpp"

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	const int SCREEN_WIDTH = 640, SCREEN_HEIGHT = 480;
	const std::string SCREEN_TITLE = "Colliders";
	SDL_Event event;
	SDL_Window* window = SDL_CreateWindow(SCREEN_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	bool isRunning = true;

	Paddle* paddle = new Paddle(20, SCREEN_HEIGHT-70);
	EventHandler handler;

	Uint32 frameStart;
	int frameTime;

	const int FPS = 30;
	const float framedelay = 1000/FPS;
	while (isRunning) {
		frameStart = SDL_GetTicks();

		handler.pollEvents(event, isRunning);
		paddle->update(handler);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // This is the Color of the Screen
		SDL_RenderClear(renderer);
		paddle->render(renderer);
		SDL_RenderPresent(renderer);

		frameTime = SDL_GetTicks() - frameStart;
		if (framedelay > frameTime)
			SDL_Delay(framedelay-frameTime);
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	delete paddle;
	return 0;
}