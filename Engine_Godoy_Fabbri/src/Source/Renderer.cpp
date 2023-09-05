#include "Renderer.h"

namespace ToToEng
{
	Renderer::Renderer()
	{
		float vertices[9] =
		{
			 0.f, .5f, 0.f,
		   -.5f, -.5f, 0.f,
			.5f, -.5f, 0.f
		};

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		std::cout << glGetString(GL_VERSION) << std::endl;
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::draw(Window* window)
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window->getWindow());

		glfwPollEvents();
	}
}
