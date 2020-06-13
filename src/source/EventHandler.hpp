#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <iostream>

class EventHandler {
private:
	SDL_Event mEvent;
public:
	EventHandler();
	void pollEvents(SDL_Event& e, bool& runningStatus);
	bool isKeyPressed(SDL_Scancode key);
};