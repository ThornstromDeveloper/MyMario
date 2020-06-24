#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

//Abstract definition of a game state
class GameState
{
	public:
		enum class StateCode
		{
			QUIT, 
			CONTINUE, 
			MAIN_MENU, 
			GAME_START, 
			GAME_INSTRUCTION, 
			GAME_OVER
		};

		virtual ~GameState() {};
		virtual void load(int stack = 0) = 0;
		virtual int unload() = 0;
		virtual StateCode update() = 0;
};

#endif //GAMESTATE_HPP