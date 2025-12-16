#include "Game.h"

#include "Character.h"
#include "Headers/GameTime.h"
#include "Headers/Settings.h"

Game::Game(bool is3D, int width, int height, const char* title) : BaseGame(is3D, width, height, title)
{
    entities.push_back(new Character(renderer));
    character = dynamic_cast<Character*>(entities.back());
    
    tileMap = new TileMap(renderer);
    tileMap->importTileMap("../res/maps/BattleCity.tmx");
    
    camera->transform.setPos({-450.f, -300.f, 10.f});
}

Game::~Game()
{
}

void Game::update()
{
    if (Input::getKey(Input::space, Input::Pressed))
        Settings::setDebugMode(!Settings::getDebugMode());
}
