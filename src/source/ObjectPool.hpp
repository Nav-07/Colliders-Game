#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include "Vector2f.hpp"
#include "Objects.hpp"

class ObjectPool {
private:
	std::vector<Objects*> objects;
public:
	void init(unsigned int layers, unsigned int maxInLayer);
	void update();
	void render(SDL_Renderer* renderer);
	void destroy();
};