#include "Player.hpp"

Player::Player(Window* window, float x, float y, int w, int h, int hp, float acceleration):
	window(window),
	acceleration(acceleration)
{
}

Player::~Player()
{
}