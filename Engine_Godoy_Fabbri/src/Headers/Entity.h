#pragma once

#include "Renderer.h"
#include "glm/glm.hpp"
#include "Exports.h"

namespace ToToEng
{
	struct Transform
	{
		glm::vec3 pos;
		glm::vec3 scale;
		glm::vec3 rotation;

		Transform()
		{
			pos = { 0, 0, 0 };
			scale = { 1, 1, 1 };
			rotation = { 0, 0, 0 };
		}
	};

	struct Vector2
	{
		float x;
		float y;
	};

	class TOTO_API Entity
	{
	protected:
		Renderer* renderer;
		Transform transform;
		float* vertices;
		unsigned int* indices;
		unsigned int VBO;
		unsigned int IBO;
		unsigned int VAO;
		unsigned int id;
		unsigned int indexQty;
		unsigned int vertexQty;

	public:
		glm::vec4 color;
		float* positions;
		float* colors;
		bool active;

		Entity(Renderer* renderer);
		virtual ~Entity();
		
		virtual void genBuffers();
		virtual void deleteBuffers();
		virtual void draw() = 0;
		virtual void updateVao();
	};
}