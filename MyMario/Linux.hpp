#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "Window.hpp"

class Animation
{
	public:
		Animation(Window* window, std::string filepath, int ammount = 1, int framerate = 0, int loops = -1);
};

#endif //ANIMATION_HPP