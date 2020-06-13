#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include "Vector2f.hpp"

class EventHandler;

class Paddle {
private:
	unsigned int mWidth, mHeight;
	Vector2f mPosition;
	SDL_Rect destRect;

	void init(Vector2f position, unsigned int width, unsigned int height);
public:
	Paddle(Vector2f position);
	void handleKeyboard();
	void update(EventHandler handler);
	void render(SDL_Renderer* renderer);
	~Paddle();
};