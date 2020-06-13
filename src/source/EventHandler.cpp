#include "EventHandler.hpp"

static const Uint8* keyboardStatus = SDL_GetKeyboardState(0);
EventHandler::EventHandler() {

}
void EventHandler::pollEvents(SDL_Event& e, bool& runningStatus) {
	this->mEvent = e;
	SDL_PollEvent(&this->mEvent);

	if (this->mEvent.type == SDL_QUIT || this->isKeyPressed(SDL_SCANCODE_ESCAPE)) {
		runningStatus = false;
	}
}
bool EventHandler::isKeyPressed(SDL_Scancode key) {
	if (keyboardStatus) {
		if (keyboardStatus[key])
			return true;
		else
			return false;
	} else {
		return false;
	}
}