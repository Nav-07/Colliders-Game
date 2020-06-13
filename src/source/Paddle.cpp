#include "Paddle.hpp"
#include "EventHandler.hpp"

void Paddle::init(unsigned int xpos, unsigned int ypos, unsigned int width, unsigned int height) {
	this->mX = xpos;
	this->mY = ypos;
	this->mWidth = width;
	this->mHeight = height;

	this->destRect.x = this->mX;
	this->destRect.y = this->mY;
	this->destRect.w = this->mWidth;
	this->destRect.h = this->mHeight;
}
Paddle::Paddle(unsigned int xpos, unsigned int ypos) {
	this->init(xpos, ypos, 120, 30);
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