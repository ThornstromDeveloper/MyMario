#ifndef GAMESTATEGAME_HPP
#define GAMESTATEGAME_HPP

#include "GameState.hpp"
#include "Window.hpp"

class GameStateGame: public GameState
{
	public:
		GameStateGame(Window* window);
		virtual ~GameStateGame();

		int unload();

	private:
		Window* window;
};

#endif //GAMESTATEGAME_HPP