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

		glBegin(GL_TRIANGLES);

		glVertex2f(-.5f, -.5f);
		glVertex2f(0.f, .5f);
		glVertex2f(.5f, -.5f);

		glEnd();

		glfwSwapBuffers(window->getWindow());

		glfwPollEvents();
	}
}