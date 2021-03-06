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
	//starting point
	float playerX = 600;
	float playerY = 300;

	//size of texture portion
	int playerW = 30;
	int playerH = 40;
	
	int hp = 100;
	float acceleration = 30;

	this->player = new Player(this->window, playerX, playerY, playerW, playerH,	100, 30);
}

int GameStateGame::unload()
{
	delete this->player;

	return 0;
}

GameState::StateCode GameStateGame::update(float dt)
{
	if (this->will_quit)
	{
		return GameState::StateCode::QUIT;
	}

	this->updateInput();

	this->player->update(dt);

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