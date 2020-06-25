#ifndef TIMER_HPP
#define TIMER_HPP

#include <string>
#include <sstream>
#include "stdint.h"

class Timer
{
	public:
		Timer();
		void start();
		void stop();
		void pause();
		void restart();
		void unpause();
		bool isRunning();
		bool isPaused();

		uint32_t delta();
		uint32_t delta_ms();
		uint32_t delta_s();
		uint32_t currentTime();

	protected:
		uint32_t startMark;
		uint32_t stopMark;
		uint32_t pausedMark;

		bool running;
		bool paused;
};

#endif //TIMER_HPP

