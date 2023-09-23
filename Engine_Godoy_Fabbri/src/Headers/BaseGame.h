#pragma once

#include "Renderer.h"
#include "Entity.h"

namespace ToToEng
{
	class BaseGame
	{
	private:
		Window* window;
		Renderer* renderer;
		Entity* entity;

	public:
		BaseGame();
		~BaseGame();

		void run();
	};
}