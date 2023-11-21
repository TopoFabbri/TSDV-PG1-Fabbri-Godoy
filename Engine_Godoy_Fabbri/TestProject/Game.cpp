#include "Game.h"

#include "Character.h"

Game::Game(bool is3D, int width, int height, const char* title) : BaseGame(is3D, width, height, title)
{
    entities.push_back(new Shape(renderer));
    entities.push_back(new Character(renderer));
    
    entities.front()->setIsTrigger(true);
    entities.front()->setColor(vec4(0.0f, 0.f, 0.f, 1.f));
    entities.front()->transform.setScale(vec3(width,height,0.f));
    
    Character* character = new Character(renderer);
    character->setIsTrigger(true);
    character->loadTexture("../res/textures/fondo.jpg");
   character->transform.setScale(vec3(800, 400,0));
    //character->transform.setPos(vec3(900,900,0));
    entities.push_back(character);
    //entities.back()->setColor(vec4(entities.back()->getColor().x,entities.back()->getColor().y, entities.back()->getColor().z, 1.f ));
    
}

Game::~Game()
{
}

void Game::update()
{
    camera->transform.lerpPos2D(entities.front()->transform.getPos() - vec3(400.f, 300.f, 0), .1f);
}