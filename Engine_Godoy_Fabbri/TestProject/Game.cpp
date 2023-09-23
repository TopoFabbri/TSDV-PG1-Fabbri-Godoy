#include "Game.h"

Game::Game()
{
	entities.push_back(new ToToEng::Shape(renderer));
}

Game::~Game()
{
}

void Game::update()
{
}