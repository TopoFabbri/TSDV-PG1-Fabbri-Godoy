#include "Entity.h"

namespace ToToEng
{
	Entity::Entity(Renderer* renderer)
	{
		this->renderer = renderer;

		color = { 1, 1, 1, 1 };

		vertices = new float();
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