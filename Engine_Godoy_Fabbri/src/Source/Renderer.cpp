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

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		std::cout << glGetString(GL_VERSION) << std::endl;
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
}
