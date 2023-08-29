#pragma once

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