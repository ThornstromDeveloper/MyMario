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
	Rectangle* frameBox = nullptr;
	bool flip;
	
	//player standing left
	frameBox = new Rectangle(85, 110, w, h);
	flip = false;
	tmp = new Animation(this->window, frameBox, "resource/smb3_mario_sheet.png", frames, frameRate, flip);
	this->animations[STANDING_LEFT] = tmp;

	//player standing right
	frameBox = new Rectangle(85, 110, w, h);
	flip = true;
	tmp = new Animation(this->window, frameBox, "resource/smb3_mario_sheet.png", frames, frameRate, flip);
	this->animations[STANDING_RIGHT] = tmp;

	//current animation state
	this->currentAnimation = this->animations[STANDING_RIGHT];
}

Player::~Player()
{
	delete this->currentAnimation;
}

void Player::update()
{
	this->preUpdate();
	this->updateInput();
	this->updateAnimation();
}

void Player::render()
{
	bool flip = this->currentAnimation->flip;
	this->currentAnimation->render(this->position->x, this->position->y, flip);
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