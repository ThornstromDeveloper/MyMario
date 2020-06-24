#include "InputManager.hpp"

InputManager* InputManager::instance = nullptr;

InputManager::InputManager():
	will_quit(false)
{ 
}

InputManager* InputManager::getInstance()
{
	if (!instance)
	{
		instance = new InputManager();
	}

	return instance;
}