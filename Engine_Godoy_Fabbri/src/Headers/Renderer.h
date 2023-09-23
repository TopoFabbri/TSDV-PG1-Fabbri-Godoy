#pragma once

#include <fstream>
#include <string>
#include <sstream>

#include "Window.h"
#include "glm/glm.hpp"

#pragma region MACROS
#define ASSERT(x) if (!(x)) __debugbreak()
#define glCall(x) glClearError();\
	x;\
	ASSERT(glLogCall(#x, __FILE__, __LINE__))
#pragma endregion

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

		unsigned int shader;
		int u_ColorLocation;
		Attribute vertexAttrib;

		static unsigned int compileShader(unsigned int type, const char* source);
		static unsigned int createShader(const char* vShader, const char* fShader);
		static ShaderProgramSource parseShader(const std::string& filepath);
		static void glClearError();
		static bool glLogCall(const char* function, const char* file, int line);

	public:
		Renderer();
		~Renderer();

		void beginDraw();
		void endDraw(Window* window);
		void genVertexBuffer(unsigned int& VBO, unsigned int& VAO, float vertices[], unsigned int id, unsigned int qty);
		void genIndexBuffer(unsigned int& IBO,
			unsigned int indices[], unsigned int id, unsigned int qty);
		void deleteBuffers(unsigned int& VBO, unsigned int& IBO, unsigned int& EBO, unsigned int id);
		void drawEntity2D(unsigned int& VAO, unsigned int indexQty, glm::vec4 color);
	};
}