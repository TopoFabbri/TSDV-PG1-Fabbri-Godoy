#pragma once

#include "Window.h"

namespace ToToEng
{
	class Renderer
	{
	private:
		unsigned int VBO;

	public:
		Renderer();
		~Renderer();

		void draw(Window* window);
	};
}