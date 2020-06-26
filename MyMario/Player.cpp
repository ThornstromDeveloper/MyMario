#include "Player.hpp"
#include "InputManager.hpp"
#include "InputDefinitions.hpp"
#include <iostream>

Player::Player(Window* window, float x, float y, int w, int h, int hp, float acceleration):
	window(window),
	acceleration(acceleration),
	currentAnimation(nullptr),
	facingDirection(RIGHT)
{
	Animation* tmp = nullptr;

	this->animations.resize(ANIMATION_MAX);

	tmp = new Animation(this->window, "resource/smb3_mario_sheet.png", 6, 2);
	this->animations[STANDING_LEFT] = tmp;

	tmp = new Animation(this->window, "resource/smb3_enemies.png", 6, 2);
	this->animations[STANDING_RIGHT] = tmp;

	this->currentAnimation = this->animations[STANDING_RIGHT];
}

Player::~Player()
{
}

void Player::update()
{
	this->updateInput();
	this->updateAnimation();
}

void Player::render()
{
	this->currentAnimation->render(0,0);
}

void Player::updateInput()
{
	InputManager* input = InputManager::getInstance();

	if (input->isKeyPressed(KEY_LEFT))
	{
		if (this->facingDirection != LEFT) {
			this->willChangeAnimation = true;
		}

		this->facingDirection = LEFT;
	}

	if (input->isKeyPressed(KEY_RIGHT))
	{
		if (this->facingDirection != RIGHT) {
			this->willChangeAnimation = true;
		}

		this->facingDirection = RIGHT;
		std::cout << "right key pressed\n";
	}
}

void Player::updateAnimation()
{
	//advance frame
	this->currentAnimation->update();

	//change animation
	if (this->willChangeAnimation)
	{
		Animation* tmp = nullptr;

		if (this->facingDirection == RIGHT && this->willChangeAnimation)
		{
			tmp = this->animations[STANDING_RIGHT];
		}
		else if (this->facingDirection == LEFT && this->willChangeAnimation)
		{
			this->willChangeAnimation = true;
			tmp = this->animations[STANDING_LEFT];
		}

		this->currentAnimation = tmp;
	}

	this->willChangeAnimation = false;
}