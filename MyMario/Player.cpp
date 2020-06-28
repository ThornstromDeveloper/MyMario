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
	willChangeAnimation(false),
	ducking(false)
{
	Animation* tmp = nullptr;	

	this->animations.resize(ANIMATION_MAX);

	int frames = 1;
	int frameRate = 30;
	Rectangle* frameBox = nullptr;
	bool flip;
	std::string frameSheet = "resource/smb3_mario_sheet.png";
	
	//player standing left/right
	frameBox = new Rectangle(0, 80, w, h);

	tmp = new Animation(this->window, frameBox, frameSheet, frames, frameRate, flip = false);
	this->animations[STANDING_LEFT] = tmp;

	tmp = new Animation(this->window, frameBox, frameSheet, frames, frameRate, flip = true);
	this->animations[STANDING_RIGHT] = tmp;

	//player ducking left
	frameBox = new Rectangle(120, 80, w, h);

	tmp = new Animation(this->window, frameBox, frameSheet, frames, frameRate, flip = false);
	this->animations[DUCKING_LEFT] = tmp;

	tmp = new Animation(this->window, frameBox, frameSheet, frames, frameRate, flip = true);
	this->animations[DUCKING_RIGHT] = tmp;

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

	this->ducking = false;

	if (input->isKeyPressed(KEY_LEFT))
	{
		this->facingDirection = Player::FacingDirection::LEFT;
	}

	if (input->isKeyPressed(KEY_RIGHT))
	{
		this->facingDirection = Player::FacingDirection::RIGHT;
	}

	if (input->isKeyPressed(KEY_DOWN))
	{
		this->ducking = true;
	}
}

void Player::updateAnimation()
{
	//advance frame
	this->currentAnimation->update();

	Animation* tmp = nullptr;

	//change facing direction
	if (this->ducking)
	{
		if (this->facingDirection == Player::FacingDirection::RIGHT)
		{
			tmp = this->animations[DUCKING_RIGHT];
		}
		else if (this->facingDirection == Player::FacingDirection::LEFT)
		{
			tmp = this->animations[DUCKING_LEFT];
		}
	}
	else
	{
		if (this->facingDirection == Player::FacingDirection::RIGHT)
		{
			tmp = this->animations[STANDING_RIGHT];
		}
		else if (this->facingDirection == Player::FacingDirection::LEFT)
		{
			tmp = this->animations[STANDING_LEFT];
		}
	}

	this->currentAnimation = tmp;
	this->willChangeAnimation = false;
}