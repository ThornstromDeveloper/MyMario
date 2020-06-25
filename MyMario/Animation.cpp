#include "Animation.hpp"
#include "Sprite.hpp"

Animation::Animation(Window* window, std::string filename, int ammount, int framerate, int loops):
	Sprite(window, filename)
{
}