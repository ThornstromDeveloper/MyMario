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
	walking_left(false),
	walking_right(false),
	ducking(false)
{
	Animation* tmp = nullptr;	

	this->animations.resize(ANIMATION_MAX);

	//parameters
	Rectangle* frameBox = nullptr;
	std::string frameSheet = "resource/smb3_mario_sheet.png";
	int frames;
	int frameRate = 30;
	bool flip;
	
	//standing
	frameBox = new Rectangle(0, 80, w, h);

	tmp = new Animation(this->window, frameBox, frameSheet, frames = 1, frameRate, flip = false);
	this->animations[STANDING_LEFT] = tmp;

	tmp = new Animation(this->window, frameBox, frameSheet, frames  = 1, frameRate, flip = true);
	this->animations[STANDING_RIGHT] = tmp;

	//ducking
	frameBox = new Rectangle(120, 80, w, h);

	tmp = new Animation(this->window, frameBox, frameSheet, frames = 1, frameRate, flip = false);
	this->animations[DUCKING_LEFT] = tmp;

	tmp = new Animation(this->window, frameBox, frameSheet, frames = 1, frameRate, flip = true);
	this->animations[DUCKING_RIGHT] = tmp;

	//walking
	frameBox = new Rectangle(30, 80, w, h);

	tmp = new Animation(this->window, frameBox, frameSheet, frames = 1, frameRate, flip = false);
	this->animations[WALKING_LEFT] = tmp;

	tmp = new Animation(this->window, frameBox, frameSheet, frames = 1, frameRate, flip = true);
	this->animations[WALKING_RIGHT] = tmp;

	//current animation state
	this->currentAnimation = this->animations[STANDING_RIGHT];
	this->currentAnimation->start();
}

Player::~Player()
{
	delete this->currentAnimation;
}

void Player::update(float dt)
{
	this->preUpdate(dt);
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
	this->walking_left = false;
	this->walking_right = false;

	if (input->isKeyPressed(KEY_LEFT))
	{
		this->facingDirection = Player::FacingDirection::LEFT;
		this->walking_left = true;
	}

	if (input->isKeyPressed(KEY_RIGHT))
	{
		this->facingDirection = Player::FacingDirection::RIGHT;
		this->walking_right = true;
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

	//ducking
	if (this->ducking)
	{
		if (this->facingDirection == Player::FacingDirection::RIGHT && this->currentAnimation != this->animations[DUCKING_RIGHT])
		{
			tmp = this->animations[DUCKING_RIGHT];
			this->willChangeAnimation = true;
		}
		else if (this->facingDirection == Player::FacingDirection::LEFT && this->currentAnimation != this->animations[DUCKING_LEFT])
		{
			tmp = this->animations[DUCKING_LEFT];
			this->willChangeAnimation = true;
		}
	}
	//walking
	else if (this->walking_left || this->walking_right)
	{
		if (this->facingDirection == Player::FacingDirection::RIGHT && this->currentAnimation != this->animations[WALKING_RIGHT])
		{
			tmp = this->animations[WALKING_RIGHT];
			this->willChangeAnimation = true;
		}
		else if (this->facingDirection == Player::FacingDirection::LEFT && this->currentAnimation != this->animations[WALKING_LEFT])
		{
			tmp = this->animations[WALKING_LEFT];
			this->willChangeAnimation = true;
		}
	}
	//standing
	else
	{
		if (this->facingDirection == Player::FacingDirection::RIGHT && this->currentAnimation != this->animations[STANDING_RIGHT])
		{
			tmp = this->animations[STANDING_RIGHT];
			this->willChangeAnimation = true;
		}
		else if (this->facingDirection == Player::FacingDirection::LEFT && this->currentAnimation != this->animations[STANDING_LEFT])
		{
			tmp = this->animations[STANDING_LEFT];
			this->willChangeAnimation = true;
		}
	}

	if (this->willChangeAnimation)
	{
		this->currentAnimation = tmp;
		this->willChangeAnimation = false;
	}
}