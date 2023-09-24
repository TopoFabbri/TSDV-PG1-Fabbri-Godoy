#include "BaseGame.h"

namespace ToToEng
{
	BaseGame::BaseGame(bool is3D)
	{
		camera = new Camera();
		window = new Window(500, 500, "Example");
		renderer = new Renderer(window, camera, is3D);

		camera->transform.setPos({ 0, 0, 1 });
		input = new Input(window->getWindow());
	}

	BaseGame::~BaseGame()
	{
		delete input;
		delete renderer;
		delete window;
		delete camera;

		for (int i = 0; i < static_cast<int>(entities.size()); i++)
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