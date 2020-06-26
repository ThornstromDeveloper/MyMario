#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "Animation.hpp"
#include "Window.hpp"

class Player
{
	public:
		enum FacingDirection { LEFT, RIGHT };
		enum PossibleAnimation
		{
			STANDING_LEFT,
			STANDING_RIGHT,
			ANIMATION_MAX
		};

		Player(Window* window, float x, float y, int w, int h, int hp, float acceleration);
		virtual ~Player();

		void update();
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
};

#endif //PLAYER_HPP