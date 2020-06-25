#include "Player.hpp"

Player::Player(Window* window, float x, float y, int w, int h, int hp, float acceleration):
	window(window),
	acceleration(acceleration),
	currentAnimation(nullptr)
{
	Animation* tmp = nullptr;

	this->animations.resize(ANIMATION_MAX);

	tmp = new Animation(this->window, "resource/smb3_mario_sheet.png", 6, 2);
	this->animations[STANDING_RIGHT] = tmp;

	this->currentAnimation = this->animations[STANDING_RIGHT];
}

Player::~Player()
{
}

void Player::render()
{
}