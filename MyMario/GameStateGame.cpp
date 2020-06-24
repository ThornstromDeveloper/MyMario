#include "GameStateGame.hpp"
#include "Player.hpp"

GameStateGame::GameStateGame(Window* window):
	window(window)
{
}

GameStateGame::~GameStateGame()
{
}

void GameStateGame::load(int stack)
{
	int playerW = 14;
	int playerH = 27;

	int playerX = 0;
	int playerY = 0;

	this->player = new Player(this->window, playerX, playerY, playerW, playerH,	100, 30);
}

int GameStateGame::unload()
{
	return 0;
}