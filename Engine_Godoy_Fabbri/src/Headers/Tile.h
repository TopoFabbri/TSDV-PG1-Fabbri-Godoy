#pragma once
#ifndef TILE_H
#define TILE_H
#include "Sprite.h"

namespace ToToEng
{
    class Tile : public Sprite
    {
    public:
        explicit Tile(Renderer* renderer);
        ~Tile() override;

        bool isWalkable() const;
        void walkability(bool bWalkable);

        unsigned int getId() const;
        void setId(unsigned int id);
        void setPosX(float x);
        void setPosY(float y);
        void setTexture(unsigned int texture);

    private:
        unsigned int id;
        bool walkable;
        vec2 pos;
    };
#endif
}
