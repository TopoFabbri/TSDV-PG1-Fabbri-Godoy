#include "GameTime.h"

void GameTime::update()
{
    delta = (float)glfwGetTime() - time;
    time = (float)glfwGetTime();
}

void GameTime::resetTime()
{
    delta = 0;
    time = static_cast<float>(glfwGetTime());
}

float GameTime::getDelta()
{
    return delta;
}

float GameTime::getTime()
{
    return time;
}
