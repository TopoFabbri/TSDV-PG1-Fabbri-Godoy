#include "BaseGame.h"

namespace ToToEng
{
	BaseGame::BaseGame()
	{
		window = new Window(500, 500, "Example");
		renderer = new Renderer();
		entity = new Entity(renderer);
	}

	BaseGame::~BaseGame()
	{
		delete entity;
		delete renderer;
		delete window;
	}

	void BaseGame::run()
	{
		while (!window->shouldClose())
		{
			renderer->beginDraw();

			entity->draw();

			renderer->endDraw(window);
		}
	}
}