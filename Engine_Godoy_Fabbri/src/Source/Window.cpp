#include "Window.h"

namespace ToToEng
{
	Window::Window()
	{
		width = 854;
		height = 480;
		title = "Example game";

		window = NULL;

		if (!glfwInit())
			return;

		window = glfwCreateWindow(width, height, "Example game", NULL, NULL);

		if (!window)
		{
			delete this;
			return;
		}

		/* Make the window's context current */
		glfwMakeContextCurrent(window);
	}

	Window::Window(int width, int height, const char* title)
	{
		this->width = width;
		this->height = height;
		this->title = title;

		window = NULL;

		if (!glfwInit())
			return;

		window = glfwCreateWindow(width, height, title, NULL, NULL);

		if (!window)
		{
			delete this;
			return;
		}

		/* Make the window's context current */
		glfwMakeContextCurrent(window);
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	GLFWwindow* Window::getWindow()
	{
		return window;
	}

	bool Window::shouldClose()
	{
		return glfwWindowShouldClose(window);
	}
}