#include "Renderer.h"

namespace ToToEng
{
	Renderer::Renderer()
	{
		float vertices[8] =
		{
			-.5f, -.5f,
			.5f, -.5f,
			-.5f, .5f,
			.5f, .5f
		};

		vertexAttrib = { 0, 2, sizeof(float) * 2, 0 };

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(vertexAttrib.index, vertexAttrib.size, GL_FLOAT, GL_FALSE, vertexAttrib.stride, 0);

		std::string vShader =
			"#version 330 core\n"
			"layout(location = 0) in vec4 position;"
			"void main()"
			"{"
			"	gl_Position = position;"
			"}";

		std::string fShader =
			"#version 330 core\n"
			"layout(location = 0) out vec4 color;"
			"void main()"
			"{"
			"	color = vec4(0.0, 1.0, 0.0, 1.0);"
			"}";

		std::cout << glGetString(GL_VERSION) << std::endl;

		unsigned int shader = CreateShader(vShader.c_str(), fShader.c_str());
		glUseProgram(shader);
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::draw(Window* window)
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 4);
		glDrawArrays(GL_TRIANGLES, 1, 4);

		glfwSwapBuffers(window->getWindow());

		glfwPollEvents();
	}

	unsigned int Renderer::CompileShader(unsigned int type, const char* source)
	{
		unsigned int id = glCreateShader(type);
		glShaderSource(id, 1, &source, nullptr);
		glCompileShader(id);

		int result;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);

		if (!result)
		{
			int length;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			char* message = new char[length];
			glGetShaderInfoLog(id, length, &length, message);

			std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader" << std::endl;
			std::cout << message << std::endl;

			glDeleteShader(id);
			return 0;
		}

		return id;
	}

	unsigned int Renderer::CreateShader(const char* vShader, const char* fShader)
	{
		unsigned int program = glCreateProgram();
		unsigned int vs = CompileShader(GL_VERTEX_SHADER, vShader);
		unsigned int fs = CompileShader(GL_VERTEX_SHADER, fShader);

		glAttachShader(program, vs);
		glAttachShader(program, fs);
		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vs);
		glDeleteShader(fs);

		return program;
	}
}