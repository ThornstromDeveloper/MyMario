#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

#include "Window.hpp"

class StateManager
{
	public:
		StateManager(Window* window);
		virtual ~StateManager();

		void run();

	private:
		Window* window;
};

#endif //STATEMANAGER_HPP