#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

//Abstract definition of a game state
class GameState
{
	public:
		enum class StateCode
		{
			QUIT, 
			CONTINUE
		};

		virtual ~GameState() {};

		virtual void load(int stack = 0) = 0;
		virtual int unload() = 0;
		virtual StateCode update(float dt) = 0;
		virtual void render() = 0;
};

#endif //GAMESTATE_HPP