#include "Entity2D.h"

ToToEng::Entity2D::Entity2D(Renderer* renderer): Entity(renderer)
{
	vertexQty = 4;
	indexQty = 6;
	id = 1;

	transform.setScale({ 100.f, 100.f, 100.f });

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
		1.f, 1.f,
		1.f, 0.f,
		0.f, 0.f,
		0.f, 1.f
	};

	indices = new unsigned int[indexQty]
	{
		0, 1, 2,
		1, 2, 3
	};

	updateVao();
}

ToToEng::Entity2D::~Entity2D()
{
}

void ToToEng::Entity2D::draw()
{
	renderer->drawEntity2D(VAO, indexQty, color, transform.getTransformMatrix(), texture);
}