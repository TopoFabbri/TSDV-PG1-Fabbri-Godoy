#include "Game.h"

#include "Character.h"

Game::Game(bool is3D, int width, int height, const char* title) : BaseGame(is3D, width, height, title)
{
    entities.push_back(new Character(renderer));
    entities.push_back(new Sprite(renderer));
}

Game::~Game()
{
}

void Game::update()
{
    camera->transform.lerpPos2D(entities.front()->transform.getPos() - vec3(400.f, 300.f, 0), .1f);
    dynamic_cast<Sprite*>(entities.back())->setTrigger(false);
}