#pragma once
#include "Entity.h"

namespace ToToEng
{
    class CollisionManager
    {
    public:
        bool checkCollision(Entity &one, Entity &two);
    };
}