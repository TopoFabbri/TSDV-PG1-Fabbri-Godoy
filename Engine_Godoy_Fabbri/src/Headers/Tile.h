#pragma once
#ifndef TILE_H
#define TILE_H
#include "Sprite.h"

namespace ToToEng
{
    class Tile sealed : public Sprite
    {
    public:
        Tile();
        Tile(const Tile& other);
        Tile(Renderer* renderer);
        ~Tile() override;

        bool isWalkable() const;
        void setWalkable(bool bWalkable);

        unsigned int getId() const;
        void setId(unsigned int id);
        void setPosX(float x);
        void setPosY(float y);
        void setTexture(uint texture, int texWidth, int texHeight);

    private:
        unsigned int id;
        bool walkable;
        vec2 pos;
    };
#endif
}
