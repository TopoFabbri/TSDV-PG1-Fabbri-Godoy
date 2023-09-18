#include "Renderer.h"

namespace ToToEng
{
	Renderer::Renderer()
	{
		float vertices[8]
		{
			-.5f, -.5f,
			.5f, -.5f,
			-.5f, .5f,
			.5f, .5f
		};

		unsigned int indices[6]
		{
			0, 1, 2,
			1, 2, 3
		};

		vertexAttrib = { 0, 2, sizeof(float) * 2, 0 };

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(vertexAttrib.index, vertexAttrib.size, GL_FLOAT, GL_FALSE, vertexAttrib.stride, 0);

		glGenBuffers(1, &IBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		ShaderProgramSource shaderSource = parseShader("../res/shaders/Basic.shader");

		std::cout << glGetString(GL_VERSION) << std::endl;

		shader = createShader(shaderSource.vertexSource.c_str(), shaderSource.fragmentSource.c_str());

		glUseProgram(shader);
	}

	Renderer::~Renderer()
	{
		glDeleteProgram(shader);
	}

	void Renderer::draw(Window* window)
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

		glfwSwapBuffers(window->getWindow());

		glfwPollEvents();
	}

	unsigned int Renderer::compileShader(unsigned int type, const char* source)
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

	unsigned int Renderer::createShader(const char* vShader, const char* fShader)
	{
		unsigned int program = glCreateProgram();
		unsigned int vs = compileShader(GL_VERTEX_SHADER, vShader);
		unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fShader);

		glAttachShader(program, vs);
		glAttachShader(program, fs);
		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vs);
		glDeleteShader(fs);

		return program;
	}

	Renderer::ShaderProgramSource Renderer::parseShader(const std::string& filepath)
	{
		std::ifstream stream(filepath);

		enum class ShaderType
		{
			None = -1,
			Vertex = 0,
			Fragment = 1
		};

		std::string line;
		std::stringstream ss[2];
		ShaderType type = ShaderType::None;

		while (std::getline(stream, line))
		{
			if (line.find("#shader") != std::string::npos)
			{
				if (line.find("vertex") != std::string::npos)
					type = ShaderType::Vertex;
				else if (line.find("fragment") != std::string::npos)
					type = ShaderType::Fragment;
			}
			else
			{
				ss[static_cast<int>(type)] << line << '\n';
			} 
		}

		return { ss[0].str(), ss[1].str() };
	}
}