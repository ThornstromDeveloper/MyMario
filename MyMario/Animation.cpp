#include "Animation.hpp"
#include "Sprite.hpp"

Animation::Animation(Window* window, Rectangle* size, std::string filename, int amount, int framerate, int loops):
	Sprite(window, filename)
{
	int x = size->x;
	int y = size->y;
	int frameW = size->w / amount;
	int frameH = size->h;

	//set part of image to display
	this->crop(Rectangle(x, y, frameW, frameH));
}

void Animation::update(float dt)
{
	this->crop(Rectangle(this->clipRect->x, this->clipRect->y, this->clipRect->w, this->clipRect->h));
}