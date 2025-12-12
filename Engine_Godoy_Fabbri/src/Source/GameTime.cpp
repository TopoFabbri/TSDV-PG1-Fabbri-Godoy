#include "GameTime.h"

#include <glfw3.h>
#include <iomanip>
#include <sstream>

namespace ToToEng
{
    GameTime* GameTime::instance = nullptr;
    
    GameTime::GameTime()
    {
        if (instance != nullptr && this != instance)
        {
            delete this;
            return;
        }
        
        time = 0.f;
        deltaTime = 0.f;
    }

    GameTime* GameTime::getInstance()
    {
        if (!instance)
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
    
    std::string GameTime::formatTime(const float timeInSeconds)
    {
        const long seconds = static_cast<long>(timeInSeconds);
        const long ms = static_cast<long>((timeInSeconds - seconds) * 1000);

        const long ss = seconds % 60;
        const long mm = (seconds / 60) % 60;
        const long hh = (seconds / 3600);

        std::ostringstream oss;
        oss << std::setfill('0') << std::setw(2) << hh << ":"
            << std::setfill('0') << std::setw(2) << mm << ":"
            << std::setfill('0') << std::setw(2) << ss << "."
            << std::setfill('0') << std::setw(3) << ms;
        return oss.str();
    }
}
