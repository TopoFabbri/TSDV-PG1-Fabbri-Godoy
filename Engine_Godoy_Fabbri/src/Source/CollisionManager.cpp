#include "CollisionManager.h"

ToToEng::CollisionManager::CollisionManager()
{
}

ToToEng::CollisionManager::~CollisionManager()
{
}

bool ToToEng::CollisionManager::checkCollision(Entity& one, Entity& two)
{
    bool collisionX = one.transform.getPos().x + one.transform.getScale().x >= two.transform.getPos().x &&
             two.transform.getPos().x + two.transform.getScale().x >= one.transform.getPos().x;
 
    bool collisionY = one.transform.getPos().y + one.transform.getScale().y >= two.transform.getPos().y &&
        two.transform.getPos().y + two.transform.getScale().y >= one.transform.getPos().y;
 
    return collisionX && collisionY;
}
