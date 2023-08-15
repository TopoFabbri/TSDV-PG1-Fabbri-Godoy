#include "BaseGame.h"

namespace ToToEng
{
	BaseGame::BaseGame()
	{
		window = new Window();
	}

	BaseGame::~BaseGame()
	{
		delete window;
	}

	void BaseGame::run()
	{
		while (!window->shouldClose())
		{
			window->updateWindow();
		}
	}
}