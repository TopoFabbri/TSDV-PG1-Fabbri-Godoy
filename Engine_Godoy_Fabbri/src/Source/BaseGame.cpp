#include "BaseGame.h"

namespace ToToEng
{
	BaseGame::BaseGame()
	{
		window = new Window(500, 500, "Example");
		renderer = new Renderer();
	}

	BaseGame::~BaseGame()
	{
		delete renderer;
		delete window;
	}

	void BaseGame::run()
	{
		while (!window->shouldClose())
		{
			renderer->draw(window);
		}
	}
}