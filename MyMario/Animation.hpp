#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "Sprite.hpp"
#include "Window.hpp"

class Animation: public Sprite
{
	public:
		Animation(Window* window, Rectangle* size, std::string filepath, int amount = 1, int framerate = 0, bool flip = false, int loops = -1);
		virtual void update(float dt = 0);

		bool flip;
};

#endif //ANIMATION_HPP