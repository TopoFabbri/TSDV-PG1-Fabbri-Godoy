#include "BoxCollider2D.h"

#include <iostream>

namespace ToToEng
{
    BoxCollider2D::BoxCollider2D(const vec2 pos, const vec2 size, Transform* transform, const bool isTrigger)
    {
        this->pos = pos;
        this->size = size;
        this->transform = transform;
        this->isTrigger = isTrigger;
        this->isStatic = false;

        upLeft = vec2(pos.x - size.x / 2, pos.y + size.y / 2);
        downRight = vec2(pos.x + size.x / 2, pos.y - size.y / 2);
    }

    vec2 BoxCollider2D::getPos(const bool colliderOnly) const
    {
        if (colliderOnly)
            return pos;

        return {transform->getPos().x + pos.x, transform->getPos().y + pos.y};
    }

    vec2 BoxCollider2D::getSize(const bool colliderOnly) const
    {
        if (colliderOnly)
            return size;

        return {transform->getScale().x * size.x, transform->getScale().y * size.y};
    }

    vec2 BoxCollider2D::getUpLeft(const bool colliderOnly) const
    {
        if (colliderOnly)
            return upLeft;

        return
        {
            transform->getPos().x + upLeft.x - transform->getScale().x / 2.f,
            transform->getPos().y + upLeft.y - transform->getScale().y / 2.f
        };
    }

    vec2 BoxCollider2D::getDownRight(const bool colliderOnly) const
    {
        if (colliderOnly)
            return downRight;

        return
        {
            transform->getPos().x + downRight.x + transform->getScale().x / 2.f,
            transform->getPos().y + downRight.y + transform->getScale().y / 2.f
        };
    }

    void BoxCollider2D::onCollision(BoxCollider2D* other)
    {
        if (isTrigger || other->isTrigger)
        {
            onTrigger(other);
            return;
        }
        
        if (onCollisionCallback)
            onCollisionCallback(other);

        if (isStatic)
            return;
        
        const vec2 aPos = getPos();
        const vec2 bPos = other->getPos();
        const vec2 aSize = getSize();
        const vec2 bSize = other->getSize();

        const vec2 delta = aPos - bPos;
        const float overlapX = aSize.x / 2.f + bSize.x / 2.f - abs(delta.x);
        const float overlapY = aSize.y / 2.f + bSize.y / 2.f - abs(delta.y);

        if (overlapX <= 0.f || overlapY <= 0.f)
            return;

        const vec3 pos = transform->getPos();

        if (overlapX < overlapY)
        {
            const float signX = delta.x >= 0.f ? 1.f : -1.f;
            transform->setPos(vec3(pos.x + signX * overlapX, pos.y, pos.z));
        }
        else
        {
            const float signY = delta.y >= 0.f ? 1.f : -1.f;
            transform->setPos(vec3(pos.x, pos.y + signY * overlapY, pos.z));
        }
    }

    void BoxCollider2D::onTrigger(BoxCollider2D* other)
    {
        if (onTriggerCallback)
            onTriggerCallback(other);
    }

    void BoxCollider2D::setOnCollision(const std::function<void(BoxCollider2D*)>& callback)
    {
        onCollisionCallback = callback;
    }

    void BoxCollider2D::setOnTrigger(const std::function<void(BoxCollider2D*)>& callback)
    {
        onTriggerCallback = callback;
    }

    bool BoxCollider2D::getIsTrigger() const
    {
        return isTrigger;
    }

    void BoxCollider2D::setTrigger(const bool isTrigger)
    {
        this->isTrigger = isTrigger;
    }

    void BoxCollider2D::setStatic(const bool isStatic)
    {
        this->isStatic = isStatic;
    }
}
