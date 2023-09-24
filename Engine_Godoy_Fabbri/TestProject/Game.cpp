#include "Game.h"

Game::Game(bool is3D, int width, int height, const char* title) : BaseGame(is3D, width, height, title)
{
	entities.push_back(new Shape(renderer));
	entities.push_back(new Shape(renderer));
}

Game::~Game()
{
}

void Game::update()
{
	Entity* character = entities.front();

	if (input->getKey(Input::a, Input::Repeated))
		character->transform.translateX(-600.f * deltaTime);
	if (input->getKey(Input::d, Input::Repeated))
		character->transform.translateX(600.f * deltaTime);

	if (input->getKey(Input::s, Input::Repeated))
		character->transform.translateY(-600.f * deltaTime);
	if (input->getKey(Input::w, Input::Repeated))
		character->transform.translateY(600.f * deltaTime);

	if (input->getKey(Input::q, Input::Repeated))
		character->transform.rotateZ(60.f * deltaTime);
	if (input->getKey(Input::e, Input::Repeated))
		character->transform.rotateZ(-60.f * deltaTime);

	camera->transform.lerpPos2D(character->transform.getPos() - vec3(400.f, 300.f, 0), .1f);

	//if (input->getKey(Input::w, Input::Repeated))
	//	camera->transform.translateY(10.f);

	//if (input->getKey(Input::a, Input::Repeated))
	//	camera->transform.translateX(-10.f);

	//if (input->getKey(Input::s, Input::Repeated))
	//	camera->transform.translateY(-10.f);

	//if (input->getKey(Input::d, Input::Repeated))
	//	camera->transform.translateX(10.f);

	//if (input->getKey(Input::q, Input::Pressed))
	//	camera->transform.rotateZ(-1.f);

	//if (input->getKey(Input::e, Input::Pressed))
	//	camera->transform.rotateZ(1.f);
}