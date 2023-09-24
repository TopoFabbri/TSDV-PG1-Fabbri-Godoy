#include "Game.h"

int main()
{
    Game* game = new Game(false);
    game->run();
    delete game;
}