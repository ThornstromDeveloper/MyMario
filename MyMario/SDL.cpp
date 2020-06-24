#include <iostream>
#include "SDL.hpp"
#include "SDL.h"
#include "SDL_image.h"

void SDL::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL Video could not initialize!" << SDL_GetError();
		return;
	}

	if (SDL_Init(IMG_INIT_PNG) < 0)
	{
		std::cout << "SDL Image could not initialize!" << IMG_GetError();
		return;
	}
}

void SDL::exit()
{
	SDL_Quit();
}