#pragma once

#include "Window.h"
#include "Renderer.h"

namespace ToToEng
{
	class BaseGame
	{
	private:
		Window* window;
		Renderer* renderer;

	public:
		BaseGame();
		~BaseGame();

		void run();
	};
}