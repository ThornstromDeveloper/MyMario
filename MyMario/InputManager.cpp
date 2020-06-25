#include "InputManager.hpp"
#include <SDL.h>
#include <iostream>

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

void InputManager::update()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.key.keysym.sym)
		{
			case SDLK_ESCAPE:
				{
					this->will_quit = true;
				}
				break;

			default:
				break;
		}
	}
}

bool InputManager::quitRequested()
{
	return this->will_quit;
}