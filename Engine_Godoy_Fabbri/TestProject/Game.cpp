#include "Game.h"

#include "Character.h"
#include "Headers/GameTime.h"

Game::Game(bool is3D, int width, int height, const char* title) : BaseGame(is3D, width, height, title)
{
    entities.push_back(new Character(renderer));
    character = dynamic_cast<Character*>(entities.back());
    
    tileMap = new TileMap(renderer);
    tileMap->importTileMap("../res/maps/TilemapTest1.tmx");
}

Game::~Game()
{
}

void Game::update()
{
    constexpr float moveSpeed = 500.f;
    
    if (Input::getKey(Input::up, Input::Repeated))
        camera->transform.setPos(camera->transform.getPos() + camera->transform.up() * GameTime::getDelta() * moveSpeed);
    
    if (Input::getKey(Input::down, Input::Repeated))
        camera->transform.setPos(camera->transform.getPos() - camera->transform.up() * GameTime::getDelta() * moveSpeed);
    
    if (Input::getKey(Input::left, Input::Repeated))
        camera->transform.setPos(camera->transform.getPos() - camera->transform.right() * GameTime::getDelta() * moveSpeed);
    
    if (Input::getKey(Input::right, Input::Repeated))
        camera->transform.setPos(camera->transform.getPos() + camera->transform.right() * GameTime::getDelta() * moveSpeed);
}
