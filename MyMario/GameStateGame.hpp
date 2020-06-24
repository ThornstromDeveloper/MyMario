#ifndef GAMESTATEGAME_HPP
#define GAMESTATEGAME_HPP

#include "GameState.hpp"
#include "Window.hpp"

class GameStateGame: public GameState
{
	public:
		GameStateGame(Window* window);
		virtual ~GameStateGame();

	private:
		Window* window;
};

#endif //GAMESTATEGAME_HPP