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

		for (int i = 0; i < entities.size(); i++)
		{
			Entity* tmp = entities.front();
			entities.pop_front();
			delete tmp;
		}

		entities.clear();
	}

	void BaseGame::run()
	{
		while (!window->shouldClose())
		{
			update();

			renderer->beginDraw();

			for (Entity* entity : entities)
				entity->draw();

			renderer->endDraw(window);
		}
	}
}