#pragma once

#include <fstream>
#include <string>
#include <sstream>

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

		struct ShaderProgramSource
		{
			std::string vertexSource;
			std::string fragmentSource;
		};

		unsigned int VBO;
		unsigned int shader;
		Attribute vertexAttrib;

		static unsigned int compileShader(unsigned int type, const char* source);
		static unsigned int createShader(const char* vShader, const char* fShader);
		static ShaderProgramSource parseShader(const std::string& filepath);

	public:
		Renderer();
		~Renderer();

		void draw(Window* window);
	};
}