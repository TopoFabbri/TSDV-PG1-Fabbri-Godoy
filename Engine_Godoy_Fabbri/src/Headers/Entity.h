#pragma once

#include "Renderer.h"

namespace ToToEng
{
	struct Transform
	{
	};

	struct Vector2
	{
		float x;
		float y;
	};

	class Entity
	{
	protected:
		Renderer* renderer;
		Transform transform;
		float* positions;
		float* colors;
		float* vertices;
		unsigned int* indices;
		unsigned int VBO;
		unsigned int IBO;
		unsigned int VAO;
		unsigned int id;
		unsigned int indexQty;
		unsigned int vertexQty;


	public:
		Entity(Renderer* renderer);
		~Entity();
		
		void genBuffers();
		void deleteBuffers();
		void draw();
		void updateVao();
	};
}