#include "Input.h"

namespace ToToEng
{
	Input::Input(GLFWwindow* window)
	{
		this->window = window;
	}

	Input::~Input()
	{
	}

	bool Input::getKey(KeyCode keyCode, Action action)
	{
		return glfwGetKey(window, keyCode) == action;
	}
}