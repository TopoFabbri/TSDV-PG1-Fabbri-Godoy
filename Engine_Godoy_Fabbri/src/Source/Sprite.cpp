#include "Sprite.h"

#include "TextureImporter.h"

ToToEng::Sprite::Sprite(Renderer* renderer) : Entity2D(renderer)
{
    loadTexture("../res/textures/AstonBirra.png");

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
        1.f, 1.f, 1.f, 1.f,
        1.f, 1.f, 1.f, 1.f,
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

void ToToEng::Sprite::draw()
{
    renderer->drawEntity2D(VAO, indexQty, color, transform.getTransformMatrix(), texture);
}

void ToToEng::Sprite::loadTexture(const char* filePath)
{
    texture = TextureImporter::loadTexture(filePath);
}
