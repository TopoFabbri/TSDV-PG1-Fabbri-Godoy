#include "Game.h"

Game::Game(bool is3D, int width, int height, const char* title) : BaseGame(is3D, width, height, title)
{
    //entities.push_back(new Shape(renderer));
    entities.push_back(new Shape(renderer));
    camera->transform.setPos(camera->transform.getPos() - vec3(400.f, 300.f, 0.0f));
}

Game::~Game()
{
}

void Game::update()
{
    Entity* triangle = entities.front();

    if (input->getKey(Input::w, Input::Repeated))
    {
        triangle->transform.setPos(triangle->transform.getPos() + vec3(0.0f, 3.0f, 0.0f) );
        triangle->transform.setScale(triangle->transform.getScale() + vec3(0.5f, 0.5f, 0.5f));
    }
    if (input->getKey(Input::s, Input::Repeated))
    {
        triangle->transform.setPos(triangle->transform.getPos() - vec3(0.0f, 3.0f, 0.0f) );
        triangle->transform.setScale(triangle->transform.getScale() + vec3(0.5f, 0.5f, 0.5f));
    }
    

    if (input->getKey(Input::t, Input::Repeated))
    {
        if (triangle->getColor().x < 1.f)
            triangle->setColor(vec4((triangle->getColor().x + 0.05f), triangle->getColor().y, triangle->getColor().z,triangle->getColor().w));
    }
    if (input->getKey(Input::r, Input::Repeated))
    {
        if (triangle->getColor().x > 0.f)
            triangle->setColor(vec4((triangle->getColor().x - 0.05f), triangle->getColor().y, triangle->getColor().z,triangle->getColor().w));
    }
    if (input->getKey(Input::h, Input::Repeated))
    {
        if (triangle->getColor().y < 1.f)
            triangle->setColor(vec4(triangle->getColor().x, (triangle->getColor().y + 0.05f), triangle->getColor().z,triangle->getColor().w));
        
    }
    if (input->getKey(Input::g, Input::Repeated))
    {
        if (triangle->getColor().y > 0.f)
            triangle->setColor(vec4(triangle->getColor().x, (triangle->getColor().y - 0.05f), triangle->getColor().z,triangle->getColor().w));
    }
    if (input->getKey(Input::n, Input::Repeated))
    {
        if (triangle->getColor().z < 1.f)
            triangle->setColor(vec4(triangle->getColor().x, triangle->getColor().y, (triangle->getColor().z + 0.05f),triangle->getColor().w));
        
    }
    if (input->getKey(Input::b, Input::Repeated))
    {
        if (triangle->getColor().z > 0.f)
            triangle->setColor(vec4(triangle->getColor().x, triangle->getColor().y, (triangle->getColor().z - 0.05f),triangle->getColor().w));
    }

   
}
