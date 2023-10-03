#pragma once

#include <glfw3.h>

#include "Exports.h"

class TOTO_API GameTime
{
    static float delta;
    static float time;

public:
    static void update();
    static void resetTime();

    static float getDelta();
    static float getTime();
};
