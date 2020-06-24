#include "GameStateGame.hpp"
#include "Player.hpp"
#include "InputManager.hpp"

GameStateGame::GameStateGame(Window* window):
	window(window),
	player(nullptr)
{
}

GameStateGame::~GameStateGame()
{
}

void GameStateGame::load(int stack)
{
	float playerX = 0;
	float playerY = 0;

	int playerW = 14;
	int playerH = 27;

	this->player = new Player(this->window, playerX, playerY, playerW, playerH,	100, 30);
}

int GameStateGame::unload()
{
	delete this->player;

	return 0;
}

GameState::StateCode GameStateGame::update()
{
	this->updateInput();

	return GameState::StateCode::CONTINUE;
}

void GameStateGame::updateInput()
{
	InputManager* input = InputManager::getInstance();
}