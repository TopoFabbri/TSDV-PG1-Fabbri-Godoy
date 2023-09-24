#include "Game.h"

Game::Game(bool is3D) : BaseGame(is3D)
{
	entities.push_back(new ToToEng::Shape(renderer));
	entities.front()->transform.setPos({ 250.f, 250.f, 0.f });
}

Game::~Game()
{
}

void Game::update()
{
	entities.front()->transform.rotateZ(1.f);
}