#include "Tile.h"

namespace ToToEng
{
    Tile::Tile() : Sprite(nullptr)
    {
        id = 0;
        walkable = true;
        pos = {0.f, 0.f};
        collider = new BoxCollider2D({0.f, 0.f}, {1.f, 1.f}, &transform, false);
    }

    Tile::Tile(Renderer* renderer) : Sprite(renderer)
    {
        id = 0;
        walkable = false;
        pos = {0.f, 0.f};
        collider = new BoxCollider2D({0.f, 0.f}, {1.f, 1.f}, &transform, false);
    }

    Tile::~Tile() = default;

    bool Tile::isWalkable() const
    {
        if (!walkable)
            return false;

        else
            return true;
    }

    void Tile::walkability(const bool bWalkable)
    {
        walkable = bWalkable;
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
    }

    void Tile::setPosY(const float y)
    {
        pos.y = y;
    }

    void Tile::setTexture(unsigned int texture)
    {
        this->texture = texture;
    }
}
