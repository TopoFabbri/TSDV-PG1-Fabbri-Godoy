#include "Shape.h"

ToToEng::Shape::Shape(Renderer* renderer) : Entity2D(renderer)
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
		1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};

	indices = new unsigned int[indexQty]
	{
		0, 1, 2,
		1, 2, 3
	};

	updateVao();
}

ToToEng::Shape::~Shape()
{
}