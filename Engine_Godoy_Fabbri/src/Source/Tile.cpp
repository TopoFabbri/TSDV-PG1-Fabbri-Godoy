#include "Tile.h"

namespace ToToEng
{
    Tile::Tile() : Sprite(nullptr)
    {
        id = 0;
        walkable = true;
        pos = {0.f, 0.f};
        collider = new BoxCollider2D({0.f, 0.f}, {1.f, 1.f}, &transform, false);
        collider->setStatic(true);
    }

    Tile::Tile(Renderer* renderer) : Sprite(renderer)
    {
        id = 0;
        walkable = false;
        pos = {0.f, 0.f};
        collider = new BoxCollider2D({0.f, 0.f}, {1.f, 1.f}, &transform, false);
        collider->setStatic(true);
    }

    Tile::Tile(const Tile& other) : Sprite(other.renderer)
    {
        id = other.id;
        walkable = other.walkable;
        pos = other.pos;
        texture = other.texture;
        texWidth = other.texWidth;
        texHeight = other.texHeight;
        
        if (other.collider)
            collider = new BoxCollider2D(other.collider->getPos(), other.collider->getSize(), &transform, false);

        setOffset(other.uvOffset);
        setScale(other.uvScale);
        
        collider->setStatic(true);
    }

    Tile::~Tile() = default;

    bool Tile::isWalkable() const
    {
        return walkable;
    }

    void Tile::setWalkable(const bool bWalkable)
    {
        walkable = bWalkable;
        
        if (bWalkable)
        {
            delete collider;
            collider = nullptr;
        }
    }

    unsigned int Tile::getId() const
    {
        return id;
    }

    void Tile::setId(const unsigned int id)
    {
        this->id = id;
    }

    void Tile::setPosX(const float x)
    {
        pos.x = x;

        transform.setPos({pos.x, pos.y, transform.getPos().z});
    }

    void Tile::setPosY(const float y)
    {
        pos.y = y;

        transform.setPos({pos.x, pos.y, transform.getPos().z});
    }

    void Tile::setPosZ(const float z)
    {
        transform.setPos({pos.x, pos.y, z});
    }

    void Tile::setTexture(const uint texture, const int texWidth, const int texHeight)
    {
        this->texture = texture;
        this->texWidth = texWidth;
        this->texHeight = texHeight;
    }
}
