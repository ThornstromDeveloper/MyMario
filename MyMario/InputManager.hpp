#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include "InputDefinitions.hpp"

class InputManager
{
	public:
		static InputManager* getInstance();
		void update();
		bool isKeyPressed(KeyboardKey key);
		bool quitRequested();

		InputManager();
		void operator=(InputManager const&) {};

	private:
		static InputManager* instance;
		const uint8_t* keyboard;
		bool keyDown[KEYBOARD_SIZE];
		bool will_quit;
};

#endif //INPUTMANAGER_HPP