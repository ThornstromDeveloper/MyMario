#include <iostream>
#include "SDL.hpp"
#include "SDL.h"

void SDL::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL Video could not initialize!" << SDL_GetError();
	}
}

void SDL::exit()
{
	SDL_Quit();
}