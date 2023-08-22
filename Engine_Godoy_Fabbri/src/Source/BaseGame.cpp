#include "BaseGame.h"

namespace ToToEng
{
	BaseGame::BaseGame()
	{
		window = new Window();
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