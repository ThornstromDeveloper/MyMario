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
		//how many milliseconds the last frame took
		unsigned int delta_ms = this->window->getDelta();

		//how many seconds have passed since last frame
		float delta = (float)(delta_ms) / 1000.0;

		GameState::StateCode whatToDoNow;

		whatToDoNow = this->currentState->update(delta);

		switch (whatToDoNow)
		{
			case GameState::StateCode::CONTINUE:
				break;

			case GameState::StateCode::QUIT:
				letsQuit = true;
				break;

			default:
				break;
		}

		if (this->window)
		{
			this->window->clear();
			this->currentState->render();
			this->window->refresh();
		}
	}
}