#include "InputManager.hpp"
#include "InputDefinitions.hpp"
#include <SDL.h>
#include <iostream>

InputManager* InputManager::instance = nullptr;

InputManager::InputManager():
	keyboard(nullptr),
	keyDown(),
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
	int i;
	for (i = 0; i < KEYBOARD_SIZE; i++)
	{
		this->keyDown[i] = false;
	}

	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				this->will_quit = true;
				break;

			case SDL_KEYDOWN:
				{
					this->keyboard = SDL_GetKeyboardState(nullptr);

					int index = event.key.keysym.scancode;

					this->keyDown[index] = true;

					if (this->keyDown[KEY_ESCAPE]) {
						this->will_quit = true;
					}
				}
				break;

			case SDL_KEYUP:
			{
				std::cout << "Key was released";
			}
			break;
		}
	}
}

bool InputManager::quitRequested()
{
	return this->will_quit;
}

bool InputManager::isKeyPressed(KeyboardKey key)
{
	if (!this->keyboard)
	{
		return false;
	}

	int sdl_key = static_cast<int>(key);

	if (this->keyboard[sdl_key])
	{
		return true;
	}

	return false;
}