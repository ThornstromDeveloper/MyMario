#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

//Abstract definition of a game state
class GameState
{
	public:
		virtual ~GameState() {};
		virtual int unload() = 0;
};

#endif //GAMESTATE_HPP