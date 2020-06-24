#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

#include "GameState.hpp"
#include "Window.hpp"

class StateManager
{
	public:
		StateManager(Window* window);
		virtual ~StateManager();

		void run();

	private:
		Window* window;
		GameState* currentState;
};

#endif //STATEMANAGER_HPP