#include "StateManager.hpp"
#include "GameStateGame.hpp"

StateManager::StateManager(Window* window):
	window(window),
	currentState(nullptr)
{
	this->currentState = new GameStateGame(this->window);
	this->currentState->load();
}

StateManager::~StateManager()
{
	if (this->currentState)
	{
		this->currentState->unload();
		delete this->currentState;

		this->currentState = nullptr;
	}
}

void StateManager::run()
{
	bool letsQuit = false;

	while (!letsQuit)
	{
		GameState::StateCode whatToDoNow;

		if (this->window)
		{
			this->window->clear();
		}

		letsQuit = true;
	}
}