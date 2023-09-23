#include "Renderer.h"

namespace ToToEng
{
	Renderer::Renderer()
	{
		vertexAttrib = { 0, 3, sizeof(float) * 7, 0 };

		ShaderProgramSource shaderSource = parseShader("../res/shaders/Basic.shader");

		std::cout << glGetString(GL_VERSION) << std::endl;

		shader = createShader(shaderSource.vertexSource.c_str(), shaderSource.fragmentSource.c_str());

		glCall(u_ColorLocation = glGetUniformLocation(shader, "u_Color"));
		_ASSERT(u_ColorLocation != -1);
	}

	Renderer::~Renderer()
	{
		glDeleteProgram(shader);
	}

	void Renderer::beginDraw()
	{
		glCall(glClear(GL_COLOR_BUFFER_BIT));
	}

	void Renderer::endDraw(Window* window)
	{
		glCall(glfwSwapBuffers(window->getWindow()));

		glCall(glfwPollEvents());
	}

	void Renderer::genVertexBuffer(unsigned int& VBO, unsigned int& VAO, float vertices[], unsigned int id, unsigned int qty)
	{
		glCall(glGenVertexArrays(id, &VAO));
		glCall(glGenBuffers(id, &VBO));

		glCall(glBindVertexArray(VAO));

		glCall(glBindBuffer(GL_ARRAY_BUFFER, VBO));
		glCall(glBufferData(GL_ARRAY_BUFFER, sizeof(float) * qty * 7, vertices, GL_STATIC_DRAW));

		glCall(glVertexAttribPointer(vertexAttrib.index, vertexAttrib.size, GL_FLOAT, GL_FALSE, vertexAttrib.stride, static_cast<void*>(0)));
		glCall(glEnableVertexAttribArray(0));
	}

	void Renderer::genIndexBuffer(unsigned int& IBO,
		unsigned int indices[], unsigned int id, unsigned int qty)
	{
		glCall(glGenBuffers(id, &IBO));
		glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO));
		glCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * qty, indices, GL_STATIC_DRAW));

		glCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
		glCall(glBindVertexArray(0));
	}

	void Renderer::deleteBuffers(unsigned int& VBO, unsigned int& IBO, unsigned int& EBO, unsigned int id)
	{
		glCall(glDeleteVertexArrays(id, &VBO));
		glCall(glDeleteBuffers(id, &IBO));
		glCall(glDeleteBuffers(id, &EBO));
		glDeleteProgram(shader);
	}

	void Renderer::drawEntity2D(unsigned int& VAO, unsigned int indexQty, glm::vec4 color)
	{
		glCall(glUseProgram(shader));

		glCall(glBindVertexArray(VAO));
		glCall(glUniform4f(u_ColorLocation, color.x, color.y, color.z, color.w));
		glCall(glDrawElements(GL_TRIANGLES, indexQty, GL_UNSIGNED_INT, 0));

		glCall(glUseProgram(0));
	}

	unsigned int Renderer::compileShader(unsigned int type, const char* source)
	{
		unsigned int id = glCreateShader(type);
		glCall(glShaderSource(id, 1, &source, nullptr));
		glCall(glCompileShader(id));

		int result;
		glCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));

		if (!result)
		{
			int length;
			glCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
			char* message = new char[length];
			glCall(glGetShaderInfoLog(id, length, &length, message));

			std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader" << std::endl;
			std::cout << message << std::endl;

			glCall(glDeleteShader(id));
			return 0;
		}

		return id;
	}

	unsigned int Renderer::createShader(const char* vShader, const char* fShader)
	{
		glCall(unsigned int program = glCreateProgram());
		glCall(unsigned int vs = compileShader(GL_VERTEX_SHADER, vShader));
		glCall(unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fShader));

		glCall(glAttachShader(program, vs));
		glCall(glAttachShader(program, fs));
		glCall(glLinkProgram(program));
		glCall(glValidateProgram(program));

		glCall(glDeleteShader(vs));
		glCall(glDeleteShader(fs));

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

	void Renderer::glClearError()
	{
		while (glGetError());
	}

	bool Renderer::glLogCall(const char* function, const char* file, int line)
	{
		while (GLenum error = glGetError())
		{
			std::cout << "[OpenGL Error] (" << error << "): "
				<< function << " " << file << ": " << line << std::endl;
			return false;
		}

		return true;
	}
}
