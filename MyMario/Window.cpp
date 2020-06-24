#include "Window.hpp"
#include <iostream>

Window::Window(std::string title):
	window(nullptr),
	surface(nullptr),
	renderer(nullptr),
	title(title)
{
	this->resize(title);

	if (!this->window || !this->renderer || !this->surface)
	{
		std::cout << "Couldn't create Window\n";
		return;
	}

	this->clear();
	this->refresh();
	SDL_Delay(500);
}

Window::~Window()
{
	this->destroy();
}

void Window::resize(std::string title)
{
	this->destroy();
	SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP, &(this->window), &(this->renderer));

	if (!this->window || !this->renderer)
	{
		std::cout << "Couldn't create SDL_Window or SDL_Renderer\n";
		return;
	}

	this->setTitle(title);

	this->surface = SDL_GetWindowSurface(this->window);

	if (!this->surface)
	{
		std::cout << "Couldn't create SDL_Surface\n";
		return;
	}
}

void Window::destroy()
{
	if (this->renderer)
	{
		SDL_DestroyRenderer(this->renderer);
		this->renderer = nullptr;
	}

	if (this->window)
	{
		SDL_DestroyWindow(this->window);
		this->window = nullptr;
	}
}

void Window::refresh()
{
	SDL_RenderPresent(this->renderer);
}

void Window::fill() {
	SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 0);
	SDL_RenderClear(this->renderer);
}

void Window::clear()
{
	this->fill();
}

void Window::setTitle(std::string title)
{
	if (this->window) {
		SDL_SetWindowTitle(this->window, title.c_str());
	}
}