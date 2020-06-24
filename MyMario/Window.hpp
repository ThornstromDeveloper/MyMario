#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <SDL.h>

class Window
{
	public:
		Window(std::string);
		virtual ~Window();
		void setTitle(std::string title);
		SDL_Window* window;

	private:
		std::string title;
};

#endif //WINDOW_HPP