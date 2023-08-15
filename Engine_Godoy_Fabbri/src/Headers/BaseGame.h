#pragma once

#include "Window.h"

namespace ToToEng
{
	class BaseGame
	{
	private:
		Window* window;

	public:
		BaseGame();
		~BaseGame();

		void run();
	};
}