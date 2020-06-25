#include "Animation.hpp"
#include "Sprite.hpp"

Animation::Animation(Window* window, std::string filename, int amount, int framerate, int loops):
	Sprite(window, filename)
{
	int frameW = this->getWidth() / amount;
	int frameH = this->getHeight();

	this->crop(Rectangle(0, 0, frameW, frameH));
}