#include "Entity.h"

namespace ToToEng
{
	Entity::Entity(Renderer* renderer)
	{
		this->renderer = renderer;

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

		indices = new unsigned int[]
		{
			0, 1, 2,
			1, 2, 3
		};

		updateVao();
	}

	Entity::~Entity()
	{
		delete positions;
		delete colors;
		delete vertices;
		delete indices;

		deleteBuffers();
	}

	void Entity::genBuffers()
	{
		renderer->genVertexBuffer(VBO, VAO, vertices, id, vertexQty);
		renderer->genIndexBuffer(IBO, indices, id, indexQty);
	}

	void Entity::deleteBuffers()
	{
		renderer->deleteBuffers(VBO, IBO, VAO, id);
	}

	void Entity::draw()
	{
		renderer->drawEntity2D(VBO, indexQty);
	}

	void Entity::updateVao()
	{
		delete vertices;
		vertices = new float[vertexQty * 7];

		for (unsigned int i = 0; i < vertexQty; i++)
		{
			vertices[7 * i] = positions[i * 3];
			vertices[7 * i + 1] = positions[i * 3 + 1];
			vertices[7 * i + 2] = positions[i * 3 + 2];

			vertices[7 * i + 3] = colors[i * 4];
			vertices[7 * i + 4] = colors[i * 4 + 1];
			vertices[7 * i + 5] = colors[i * 4 + 2];
			vertices[7 * i + 6] = colors[i * 4 + 3];
		}

		genBuffers();
	}
}