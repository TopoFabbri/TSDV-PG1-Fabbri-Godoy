#include <glfw3.h>

#include "BaseGame.h"

int main(void)
{
    ToToEng::BaseGame* baseGame = new ToToEng::BaseGame();
    baseGame->run();
    delete baseGame;
}