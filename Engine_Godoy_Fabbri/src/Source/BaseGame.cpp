#include "BaseGame.h"

namespace ToToEng
{
	BaseGame::BaseGame(bool is3D)
	{
		camera = new Camera();
		window = new Window(500, 500, "Example");
		renderer = new Renderer(window, camera, is3D);

		camera->transform.setPos({ 0, 0, 1 });
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
			renderer->setView(lookAt(camera->transform.getPos(), camera->transform.getPos() + camera->transform.forward(), camera->transform.up()));
			update();

			renderer->beginDraw();

			for (Entity* entity : entities)
				entity->draw();

			renderer->endDraw();
		}
	}
}