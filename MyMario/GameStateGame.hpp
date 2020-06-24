#ifndef GAMESTATEGAME_HPP
#define GAMESTATEGAME_HPP

#include "GameState.hpp"
#include "Window.hpp"
#include "InputManager.hpp"
#include "Player.hpp"

class GameStateGame: public GameState
{
	public:
		GameStateGame(Window* window);
		virtual ~GameStateGame();

		void load(int stack = 0);
		int unload();
		GameState::StateCode update();

	private:
		void updateInput();
		Window* window;
		Player* player;
};

#endif //GAMESTATEGAME_HPP