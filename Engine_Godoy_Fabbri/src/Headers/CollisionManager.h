#pragma once
#include "Entity.h"
#include "Entity2D.h"

namespace ToToEng
{
    class CollisionManager
    {
    private:
        Entity2D* entity2D;
        
    public:
        
        CollisionManager();
        ~CollisionManager();
        
        bool checkCollision(Entity &one, Entity &two);
    };
}
