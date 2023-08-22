#include "Renderer.h"

namespace ToToEng
{
	Renderer::Renderer()
	{
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::draw(Window* window)
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window->getWindow());

		glfwPollEvents();
	}
}