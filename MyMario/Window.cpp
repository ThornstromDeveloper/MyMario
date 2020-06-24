#include "Window.hpp"

Window::Window(std::string title):
	window(nullptr),
	title(title)
{
	this->setTitle(title);
}

Window::~Window()
{
}

void Window::setTitle(std::string title)
{
	if (this->window) {
		SDL_SetWindowTitle(this->window, title.c_str());
	}
}