#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <SDL.h>

class Window
{
	public:
		Window(std::string);
		virtual ~Window();

		void destroy();
		SDL_Texture* loadImage(std::string filename);
		void freeImage(SDL_Texture* image);
		void freeImage(SDL_Surface* image);
		void refresh();
		void resize(std::string title);
		void fill();
		void clear();
		void setTitle(std::string title);

		SDL_Window* window;
		SDL_Surface* surface;
		SDL_Renderer* renderer;

	private:
		std::string title;
};

#endif //WINDOW_HPP