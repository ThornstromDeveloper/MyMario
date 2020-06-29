#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "Sprite.hpp"
#include "Window.hpp"
#include "Timer.hpp"

class Animation: public Sprite
{
	public:
		Animation(Window* window, Rectangle* size, std::string filepath, int amount = 1, int framerate = 0, bool flip = false, int loops = -1);
		virtual void update(float dt = 0);

		void nextFrame();
		void firstFrame();
		void start();
		void stop();
		bool flip;

	private:
		unsigned int framerate;
		int curFrame;
		int maxFrame;
		Timer timer;
		int loops;
		int timesLooped;
};

#endif //ANIMATION_HPP