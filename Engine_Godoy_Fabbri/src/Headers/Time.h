#pragma once

#include <glfw3.h>

namespace ToToEng
{
    class Time
    {
    private:
        static float frameTime;
        static float delta;
    
    public:
        static float getDelta();
        static float getTime();

        static void update();
    };
}
