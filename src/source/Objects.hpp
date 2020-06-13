#pragma once
#include <SDL2/SDL.h>
#include <string>
#include "Vector2f.hpp"

class Objects {
private:
	Vector2f mPosition;
	SDL_Rect destRect;
public:
	Objects(Vector2f position);
	void render(SDL_Renderer* renderer);
};