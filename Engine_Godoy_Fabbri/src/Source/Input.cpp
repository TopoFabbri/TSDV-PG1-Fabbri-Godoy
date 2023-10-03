#include "Input.h"

namespace ToToEng
{
	std::list<Input::KeyCode> Input::keysPressed;

	Input::Input(GLFWwindow* window)
	{
		glfwSetKeyCallback(window, keyCallback);
		this->window = window;
	}

	Input::~Input()
	{
	}

	bool Input::getKey(KeyCode keyCode, Action action)
	{
		switch (action)
		{
			case Pressed:
			{
				bool pressed = std::find(keysPressed.begin(), keysPressed.end(), keyCode) != keysPressed.end();
				keysPressed.remove(keyCode);
				return pressed;
			}

			case Repeated:
			{
				return glfwGetKey(window, keyCode) == Pressed;
			}

			case Released:
			{
				return glfwGetKey(window, keyCode) == Released;
			}
		}

		return false;
	}

	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		switch (action)
		{
		case GLFW_RELEASE:
			Input::keysPressed.remove(static_cast<Input::KeyCode>(key));
			break;

		case GLFW_PRESS:
			Input::keysPressed.push_back(static_cast<Input::KeyCode>(key));
			break;

		default:;
		}
	}
}