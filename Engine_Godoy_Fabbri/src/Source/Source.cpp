#include "Game.h"

int main()
{
    ToToEng::Game* game = new ToToEng::Game();
    game->run();
    delete game;
}