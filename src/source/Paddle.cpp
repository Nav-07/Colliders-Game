#include "Paddle.hpp"
#include "EventHandler.hpp"

void Paddle::init(Vector2f position, unsigned int width, unsigned int height) {
	this->mPosition = position;
	this->mWidth = width;
	this->mHeight = height;

	this->destRect.x = this->mPosition.x;
	this->destRect.y = this->mPosition.y;
	this->destRect.w = this->mWidth;
	this->destRect.h = this->mHeight;
}
Paddle::Paddle(Vector2f position) {
	this->init(position, 120, 30);
}
void Paddle::handleKeyboard() {

}
void Paddle::update(EventHandler handler) {
	float vel = 3;
	if (handler.isKeyPressed(SDL_SCANCODE_A)) {
		destRect.x -= vel;
	} 
	if (handler.isKeyPressed(SDL_SCANCODE_D)) {
		destRect.x += vel;
	}
}
void Paddle::render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &destRect);
}
Paddle::~Paddle() {

}