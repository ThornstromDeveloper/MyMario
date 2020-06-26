#include "GameStateGame.hpp"
#include "Player.hpp"
#include "InputManager.hpp"

GameStateGame::GameStateGame(Window* window):
	window(window),
	will_quit(false),
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
	if (this->will_quit)
	{
		return GameState::StateCode::QUIT;
	}

	this->updateInput();

	this->player->update();

	return GameState::StateCode::CONTINUE;
}

void GameStateGame::render()
{
	this->player->render();
}

void GameStateGame::updateInput()
{
	InputManager* input = InputManager::getInstance();

	input->update();

	this->will_quit = input->quitRequested();
}