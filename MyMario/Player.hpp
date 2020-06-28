#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "FallingObject.hpp"
#include "Animation.hpp"
#include "Window.hpp"

class Player: public FallingObject
{
	public:
		enum class FacingDirection { LEFT, RIGHT };
		enum PossibleAnimation
		{
			STANDING_LEFT, STANDING_RIGHT,
			DUCKING_LEFT, DUCKING_RIGHT,
			WALKING_LEFT, WALKING_RIGHT,
			ANIMATION_MAX
		};

		Player(Window* window, float x, float y, int w, int h, int hp, float acceleration);
		virtual ~Player();

		void update(float dt);
		void render();
		void updateInput();
		void updateAnimation();

	private:
		Window* window;
		float acceleration;
		Animation* currentAnimation;
		std::vector<Animation*> animations;

		FacingDirection facingDirection;
		bool willChangeAnimation;

		bool ducking;
		bool walking_left;
		bool walking_right;
};

#endif //PLAYER_HPP