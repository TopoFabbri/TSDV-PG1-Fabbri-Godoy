#pragma once
#include "Entity.h"

namespace ToToEng
{
    class CollisionManager
    {
    public:
        bool CheckCollision(Entity &one, Entity &two); // AABB - AABB collision

    
    };
}
