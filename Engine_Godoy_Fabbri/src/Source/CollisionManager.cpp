#include "CollisionManager.h"

bool ToToEng::CollisionManager::CheckCollision(Entity& one, Entity& two)
{
    // collision x-axis?
    bool collisionX = one.transform.getPos().x + one.transform.getScale().x >= two.transform.getPos().x &&
        two.transform.getPos().x + two.transform.getScale().x >= one.transform.getPos().x;
    // collision y-axis?
    bool collisionY = one.transform.getPos().y + one.transform.getScale().y >= two.transform.getPos().y &&
        two.transform.getPos().y + two.transform.getScale().y >= one.transform.getPos().y;
    // collision only if on both axes
    return collisionX && collisionY;
}
