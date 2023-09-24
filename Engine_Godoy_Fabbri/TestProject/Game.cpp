#include "Game.h"

Game::Game(bool is3D) : BaseGame(is3D)
{
	entities.push_back(new Shape(renderer));
	entities.front()->transform.setPos({ 250.f, 250.f, 0.f });
}

Game::~Game()
{
}

void Game::update()
{
	if (input->getKey(Input::a, Input::Pressed))
		camera->transform.translateX(-10.f);
	if (input->getKey(Input::d, Input::Pressed))
		camera->transform.translateX(10.f);

	if (input->getKey(Input::s, Input::Pressed))
		camera->transform.translateY(-10.f);
	if (input->getKey(Input::w, Input::Pressed))
		camera->transform.translateY(10.f);

	if (input->getKey(Input::q, Input::Pressed))
		camera->transform.rotateZ(-1.f);
	if (input->getKey(Input::e, Input::Pressed))
		camera->transform.rotateZ(1.f);
}