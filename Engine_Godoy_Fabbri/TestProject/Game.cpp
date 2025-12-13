#include "Game.h"

#include "Character.h"
#include "Headers/GameTime.h"
#include "Headers/Settings.h"

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
    camera->transform.setPos(character->transform.getPos() + vec3{-400.f, -300.f, 10.f});
    
    if (Input::getKey(Input::space, Input::Pressed))
        Settings::setDebugMode(!Settings::getDebugMode());
}
