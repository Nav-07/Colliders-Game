#include "Objects.hpp"

Objects::Objects(Vector2f position) {
	this->mPosition = position;
	destRect.x = mPosition.x;
	destRect.y = mPosition.y;
	destRect.w = 15;
	destRect.h = 15;
}
void Objects::render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &destRect);
}