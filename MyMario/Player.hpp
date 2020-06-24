#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Window.hpp"

class Player
{
	public:
		Player(Window* window, float x, float y, int w, int h, int hp, float acceleration);
		virtual ~Player();

	private:
		Window* window;
		float acceleration;
};

#endif //GAMESTATEGAME_HPP