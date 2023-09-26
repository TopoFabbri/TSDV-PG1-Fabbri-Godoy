#include "Game.h"

Game::Game(bool is3D, int width, int height, const char* title) : BaseGame(is3D, width, height, title)
{
	speed = 100.f;
	entities.push_back(new Shape(renderer));
	entities.front()->color = { 1.f, .4f, 0.f, 1.f };
	entities.front()->transform.translateX((float)width / 2.f);
	entities.front()->transform.translateY((float)height);
}

Game::~Game()
{
}

void Game::update()
{
	if (input->getKey(Input::a, Input::Repeated))
		entities.front()->transform.translateX(-speed * deltaTime);
	if (input->getKey(Input::d, Input::Repeated))
		entities.front()->transform.translateX(speed * deltaTime);

	if (input->getKey(Input::s, Input::Repeated))
	{
		entities.front()->transform.translateY(-speed * deltaTime);
		entities.front()->transform.setScale(entities.front()->transform.getScale() + 50.f * deltaTime);
	}

	if (input->getKey(Input::w, Input::Repeated))
		entities.front()->transform.translateY(speed * deltaTime);

	if (input->getKey(Input::e, Input::Repeated))
		speed += 10.f;
	if (input->getKey(Input::q, Input::Repeated))
		speed -= 10.f;

	if (input->getKey(Input::r, Input::Repeated))
		entities.front()->transform.setScale(entities.front()->transform.getScale() - 50.f * deltaTime);
}
