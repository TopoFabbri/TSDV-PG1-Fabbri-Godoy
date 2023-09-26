#pragma once

#include <list>

#include "Window.h"
#include "Exports.h"

namespace ToToEng
{
	class TOTO_API Input
	{
	private:
		GLFWwindow* window;

	public:

		enum KeyCode
		{
			a = GLFW_KEY_A,
			d = GLFW_KEY_D,
			q = GLFW_KEY_Q,
			e = GLFW_KEY_E,
			w = GLFW_KEY_W,
			s = GLFW_KEY_S,
			r = GLFW_KEY_R,
			g = GLFW_KEY_G,
			b = GLFW_KEY_B,
			t = GLFW_KEY_T,
			h = GLFW_KEY_H,
			n = GLFW_KEY_N,
		};

		enum Action
		{
			Pressed = GLFW_PRESS,
			Repeated = GLFW_REPEAT,
			Released = GLFW_RELEASE,
		};

		struct KeyState
		{
			KeyCode key;
			Action state;
		};

		static std::list<KeyCode> keysPressed;

		Input(GLFWwindow* window);
		~Input();

		bool getKey(KeyCode keyCode, Action action);
	};

	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
}