#include "Sprite.h"

ToToEng::Sprite::Sprite(Renderer* renderer) : Entity2D(renderer)
{
    vertexQty = 4;
    indexQty = 6;
    id = 1;

    positions = new float[vertexQty * 3]
    {
        -.5f, -.5f, 0.f,
        .5f, -.5f, 0.f,
        -.5f, .5f, 0.f,
        .5f, .5f, 0.f
    };

    colors = new float[vertexQty * 4]
    {
        0.f, 0.f, 0.f, 1.f,
        0.f, 0.f, 0.f, 1.f,
        1.f, 1.f, 1.f, 1.f,
        1.f, 1.f, 1.f, 1.f
    };

    textureCoords = new float[vertexQty * 2]
    {
        0.f, 1.f,
        1.f, 1.f,
        0.f, 0.f,
        1.f, 0.f
    };

    indices = new unsigned int[indexQty]
    {
        0, 1, 2,
        1, 2, 3,
    };

    updateVao();
}

ToToEng::Sprite::~Sprite()
{
}
