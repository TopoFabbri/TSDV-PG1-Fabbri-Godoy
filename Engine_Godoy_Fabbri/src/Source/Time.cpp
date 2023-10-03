#include "Time.h"

namespace ToToEng
{
    float Time::getDelta()
    {
        return delta;
    }

    float Time::getTime()
    {
        return frameTime;
    }

    void Time::update()
    {
        delta = static_cast<float>(glfwGetTime()) - frameTime;
        frameTime = static_cast<float>(glfwGetTime());
    }
}
