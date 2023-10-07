#include "GameTime.h"

#include <glfw3.h>

namespace ToToEng
{
    GameTime* GameTime::instance = nullptr;
    
    GameTime::GameTime()
    {
        if (instance != nullptr)
            instance = this;
        
        time = 0.f;
        deltaTime = 0.f;
    }

    GameTime::~GameTime()
    = default;

    GameTime* GameTime::getInstance()
    {
        if (instance == nullptr)
            instance = new GameTime();
        
        return instance;
    }

    void GameTime::resetTime()
    {
        getInstance()->time = 0.f;
        getInstance()->deltaTime = 0.f;
    }

    void GameTime::update()
    {
        getInstance()->deltaTime = static_cast<float>(glfwGetTime()) - getInstance()->time;
        getInstance()->time = static_cast<float>(glfwGetTime());
    }

    float GameTime::getTime()
    {
        return getInstance()->time;
    }

    float GameTime::getDelta()
    {
        return getInstance()->deltaTime;
    }
}
