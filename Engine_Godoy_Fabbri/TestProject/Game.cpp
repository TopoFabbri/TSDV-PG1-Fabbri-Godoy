#include "Game.h"

Game::Game(bool is3D, int width, int height, const char* title) : BaseGame(is3D, width, height, title)
{
    entities.push_back(new Character(renderer));
    entities.push_back(new Shape(renderer));
}

Game::~Game()
{
}

void Game::update()
{
    Entity* character = entities.front();

    if (Input::getKey(Input::t, Input::Repeated))
    {
        if (character->getColor().x < 1.f)
            character->setColor(vec4((character->getColor().x + 0.05f), character->getColor().y, character->getColor().z,character->getColor().w));
    }
    if (Input::getKey(Input::r, Input::Repeated))
    {
        if (character->getColor().x > 0.f)
            character->setColor(vec4((character->getColor().x - 0.05f), character->getColor().y, character->getColor().z,character->getColor().w));
    }
    if (Input::getKey(Input::h, Input::Repeated))
    {
        if (character->getColor().y < 1.f)
            character->setColor(vec4(character->getColor().x, (character->getColor().y + 0.05f), character->getColor().z,character->getColor().w));
        
    }
    if (Input::getKey(Input::g, Input::Repeated))
    {
        if (character->getColor().y > 0.f)
            character->setColor(vec4(character->getColor().x, (character->getColor().y - 0.05f), character->getColor().z,character->getColor().w));
    }
    if (Input::getKey(Input::n, Input::Repeated))
    {
        if (character->getColor().z < 1.f)
            character->setColor(vec4(character->getColor().x, character->getColor().y, (character->getColor().z + 0.05f),character->getColor().w));
        
    }
    if (Input::getKey(Input::b, Input::Repeated))
    {
        if (character->getColor().z > 0.f)
            character->setColor(vec4(character->getColor().x, character->getColor().y, (character->getColor().z - 0.05f),character->getColor().w));
    }

    camera->transform.lerpPos2D(character->transform.getPos() - vec3(400.f, 300.f, 0), .1f);
}
