#include "Game.h"

int main()
{
    Game* game = new Game(false, 900, 600, "Test Game");
    game->run();
    delete game;
}