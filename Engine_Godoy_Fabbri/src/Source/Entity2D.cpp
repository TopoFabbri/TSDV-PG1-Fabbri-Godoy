#include "Entity2D.h"

ToToEng::Entity2D::Entity2D(Renderer* renderer) : Entity(renderer)
{
    vertexQty = 4;
    indexQty = 6;
    id = 1;

    transform.setScale({30.f, 30.f, 30.f});

    positions = new float[vertexQty * 3]{-.5f, -.5f, 0.f, .5f, -.5f, 0.f, -.5f, .5f, 0.f, .5f, .5f, 0.f};

    colors = new float[vertexQty * 4]{1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f};

    textureCoords = new float[vertexQty * 2]{0.f, 1.f, 1.f, 1.f, 0.f, 0.f, 0.f, 1.f};

    indices = new unsigned int[indexQty]{0, 1, 2, 1, 2, 3};

    uvOffset = {0, 0};
    uvScale = {1, 1};

    updateVao();

    collider = new BoxCollider2D({0.f, 0.f}, {1.f, 1.f}, &transform, true);
}

ToToEng::Entity2D::Entity2D(const Entity2D& other) : Entity(other.renderer)
{
    // 1. Copy basic values
    this->vertexQty = other.vertexQty;
    this->indexQty = other.indexQty;
    this->id = other.id;
    this->transform = other.transform; // Assuming Transform handles its own copy
    this->uvOffset = other.uvOffset;
    this->uvScale = other.uvScale;

    this->positions = new float[vertexQty * 3];
    std::copy_n(other.positions, vertexQty * 3, this->positions);

    this->colors = new float[vertexQty * 4];
    std::copy_n(other.colors, vertexQty * 4, this->colors);

    this->textureCoords = new float[vertexQty * 2];
    std::copy_n(other.textureCoords, vertexQty * 2, this->textureCoords);

    this->indices = new unsigned int[indexQty];
    std::copy_n(other.indices, indexQty, this->indices);

    this->collider = new BoxCollider2D(other.collider->getPos(), other.collider->getSize(), &this->transform, other.collider->getIsTrigger());

    updateVao();
}

ToToEng::Entity2D::~Entity2D()
{
    delete collider;
}

ToToEng::Entity2D& ToToEng::Entity2D::operator=(const Entity2D& other)
{
    if (this == &other) return *this;

    delete collider;
    delete[] positions;
    delete[] colors;
    delete[] textureCoords;
    delete[] indices;
    delete[] vertices;

    return *this;
}

void ToToEng::Entity2D::setOffset(vec2 offset)
{
    this->uvOffset = offset;

    updateVao();
}

void ToToEng::Entity2D::setScale(vec2 scale)
{
    this->uvScale = scale;

    updateVao();
}

void ToToEng::Entity2D::updateVao()
{
    delete vertices;

    vertices = new float[vertexQty * 9];

    for (unsigned int i = 0; i < vertexQty; i++)
    {
        vertices[9 * i] = positions[i * 3];
        vertices[9 * i + 1] = positions[i * 3 + 1];
        vertices[9 * i + 2] = positions[i * 3 + 2];

        vertices[9 * i + 3] = colors[i * 4];
        vertices[9 * i + 4] = colors[i * 4 + 1];
        vertices[9 * i + 5] = colors[i * 4 + 2];
        vertices[9 * i + 6] = colors[i * 4 + 3];

        vertices[9 * i + 7] = textureCoords[i * 2] * uvScale.x + uvOffset.x;
        vertices[9 * i + 8] = textureCoords[i * 2 + 1] * uvScale.y + uvOffset.y;
    }

    genBuffers();
}

void ToToEng::Entity2D::draw()
{
}

void ToToEng::Entity2D::setTrigger(bool isTrigger)
{
    collider->setTrigger(isTrigger);
}
