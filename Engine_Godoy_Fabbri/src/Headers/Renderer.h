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

		static unsigned int CompileShader(unsigned int type, const char* source);
		static unsigned int CreateShader(const char* vShader, const char* fShader);

	public:
		Renderer();
		~Renderer();

		void draw(Window* window);
	};
}