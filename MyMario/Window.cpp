#include "Window.hpp"

Window::Window(std::string title):
	window(nullptr),
	title(title)
{
	this->setTitle(title);
	this->clear();
}

Window::~Window()
{
	this->destroy();
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

void Window::fill() {
	SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, 0.8);
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