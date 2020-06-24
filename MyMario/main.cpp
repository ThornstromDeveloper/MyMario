#include "SDL.hpp"
#include "Window.hpp"
#include "StateManager.hpp"

int main(int argc, char** argv)
{
	SDL::init();

	Window window("Mario");

	StateManager manager(&window);
	manager.run();

	SDL::exit();

	return 0;
}