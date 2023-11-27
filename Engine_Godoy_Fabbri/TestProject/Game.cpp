#include "Game.h"

#include "Character.h"

Game::Game(bool is3D, int width, int height, const char* title) : BaseGame(is3D, width, height, title)
{
    entities.push_back(new Shape(renderer));
    

    entities.front()->setIsTrigger(true);
    entities.front()->setColor(vec4(0.0f, 0.f, 0.f, 1.f));
    entities.front()->transform.setScale(vec3(width, height, 0.f));

    Character* background = new Character(renderer, false, false);
    background->setIsTrigger(true);
    background->loadTexture("../res/textures/fondo.jpg");
    background->transform.setScale(vec3(800, 600, 0));
    background->transform.setPos(vec3(0, 0, 0));
    entities.push_back(background);

    entities.push_back(new Character(renderer, true, true));

    Sprite* tv = new Sprite(renderer);
    tv->addAnimation(3.f, 5, 9, "../res/textures/sonic.png",
        vec2(0.156f, 0.69f), vec2(0.06f, 0.107f));
    entities.push_back(tv);

    
}

Game::~Game()
{
}

void Game::update()
{
    camera->transform.lerpPos2D(entities.front()->transform.getPos() - vec3(400.f, 300.f, 0), .1f);
}
