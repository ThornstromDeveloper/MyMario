#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

class InputManager
{
	public:
		static InputManager* getInstance();
		InputManager();

	private:
		static InputManager* instance;
		bool will_quit;
};

#endif //INPUTMANAGER_HPP