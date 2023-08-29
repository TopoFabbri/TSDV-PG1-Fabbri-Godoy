#include "Game.h"

int main(void)
{
    ToToEng::Game* game = new ToToEng::Game();
    game->run();
    delete game;
}