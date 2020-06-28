#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <SDL.h>
#include "Shapes.hpp"
#include "Timer.hpp"

class Window
{
	public:
		Window(std::string);
		virtual ~Window();

		void destroy();
		void renderImage(SDL_Texture* texture, Rectangle* source, Rectangle* destination, bool flip);
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

		void delayFramerateIfNeeded();
		unsigned int getDelta();

	private:
		std::string title;
		Timer framerateTimer;

		unsigned int framerate;
		unsigned int frame_delay;
		unsigned int current_frame_delta;
};

#endif //WINDOW_HPP