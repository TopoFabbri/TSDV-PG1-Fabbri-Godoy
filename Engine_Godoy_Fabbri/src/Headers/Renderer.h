#pragma once

#include "Window.h"

namespace ToToEng
{
	class Renderer
	{
	private:
		struct Attribute
		{
			GLuint index;
			GLint size;
			GLsizei stride;
			const GLvoid* pointer;
		};

		unsigned int VBO;
		Attribute vertexAttrib;

	public:
		Renderer();
		~Renderer();

		void draw(Window* window);
	};
}