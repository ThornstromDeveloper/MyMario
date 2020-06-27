#include "Player.hpp"
#include "InputManager.hpp"
#include "InputDefinitions.hpp"
#include <iostream>

Player::Player(Window* window, float x, float y, int w, int h, int hp, float acceleration):
	FallingObject(x, y, w, h),
	window(window),
	acceleration(acceleration),
	currentAnimation(nullptr),
	facingDirection(Player::FacingDirection::RIGHT),
	willChangeAnimation(false)
{
	Animation* tmp = nullptr;

	this->animations.resize(ANIMATION_MAX);

	int frames = 1;
	int frameRate = 30;

	tmp = new Animation(this->window, "resource/smb3_mario_sheet.png", frames, frameRate);
	this->animations[STANDING_LEFT] = tmp;

	tmp = new Animation(this->window, "resource/smb3_enemies.png", frames, frameRate);
	this->animations[STANDING_RIGHT] = tmp;

	this->currentAnimation = this->animations[STANDING_RIGHT];
}

Player::~Player()
{
}

void Player::update()
{
	this->preUpdate();
	this->updateInput();
	this->updateAnimation();
}

void Player::render()
{
	this->currentAnimation->render(this->position->x, this->position->y);
}

void Player::updateInput()
{
	InputManager* input = InputManager::getInstance();

	if (input->isKeyPressed(KEY_LEFT))
	{
		if (this->facingDirection != Player::FacingDirection::LEFT) {
			this->willChangeAnimation = true;
		}

		this->facingDirection = Player::FacingDirection::LEFT;
	}

	if (input->isKeyPressed(KEY_RIGHT))
	{
		if (this->facingDirection != Player::FacingDirection::RIGHT) {
			this->willChangeAnimation = true;
		}

		this->facingDirection = Player::FacingDirection::RIGHT;
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

		if (this->facingDirection == Player::FacingDirection::RIGHT && this->willChangeAnimation)
		{
			tmp = this->animations[STANDING_RIGHT];
		}
		else if (this->facingDirection == Player::FacingDirection::LEFT && this->willChangeAnimation)
		{
			this->willChangeAnimation = true;
			tmp = this->animations[STANDING_LEFT];
		}

		this->currentAnimation = tmp;
	}

	this->willChangeAnimation = false;
}