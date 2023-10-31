#pragma once

#include <string>
#include <sstream>

#include "Window.h"
#include <glm/gtc/type_ptr.hpp>

#include "Camera.h"

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
		struct ShaderProgramSource
		{
			std::string vertexSource;
			std::string fragmentSource;
		};

		Window* window;
		Camera* camera;
		unsigned int shader;
		unsigned int shapeShader;
		int u_TransformLocation;
		int u_ShapeTransformLocation;
		int u_ColorLocation;
		mat4 projection;
		mat4 view;
		vec3 cameraPos;

		static unsigned int compileShader(unsigned int type, const char* source);
		static unsigned int createShader(const char* vShader, const char* fShader);
		static ShaderProgramSource parseShader(const std::string& filepath);
		static void glClearError();
		static bool glLogCall(const char* function, const char* file, int line);

	public:
		Renderer(Window* window, Camera* camera, bool is3D);
		~Renderer();

		void beginDraw();
		void endDraw();
		void genVertexBuffer(unsigned int& VBO, unsigned int& VAO, float vertices[], unsigned int id, unsigned int qty);
		void genIndexBuffer(unsigned int& IBO,
			unsigned int indices[], unsigned int id, unsigned int qty);
		void deleteBuffers(unsigned int& VBO, unsigned int& IBO, unsigned int& EBO, unsigned int id);
		void drawEntity2D(unsigned int& VAO, unsigned int indexQty, vec4 color, mat4 trans, unsigned int texture);
		void drawShape(unsigned int& VAO, unsigned int indexQty, vec4 color, mat4 trans);
		void setProjection(mat4 projection);
		void setView(mat4 view);
		unsigned int loadTexture(const char* filePath);
	};
}