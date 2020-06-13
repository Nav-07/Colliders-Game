#include <SDL2/SDL.h>
#include <string>
#include <iostream>

class EventHandler;
class Paddle {
private:
	unsigned int mWidth, mHeight;
	unsigned int mX, mY;
	SDL_Rect destRect;

	void init(unsigned int xpos, unsigned int ypos, unsigned int width, unsigned int height);
public:
	Paddle(unsigned int xpos, unsigned int ypos);
	void handleKeyboard();
	void update(EventHandler handler);
	void render(SDL_Renderer* renderer);
	~Paddle();
};