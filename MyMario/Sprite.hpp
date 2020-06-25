#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "Window.hpp"

class Sprite
{
	public:
		Sprite(Window* window, std::string filename);
		virtual ~Sprite();

	protected:
		Window* window;
		std::string filename;
};

#endif //SPRITE_HPP