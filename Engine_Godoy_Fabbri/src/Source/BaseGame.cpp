#include "BaseGame.h"

namespace ToToEng
{
	BaseGame::BaseGame(bool is3D, int width, int height, const char* title)
	{
		camera = new Camera();
		window = new Window(width, height, title);
		renderer = new Renderer(window, camera, is3D);

		camera->transform.setPos({ 0, 0, 1 });
		input = new Input(window->getWindow());

		deltaTime = 0;
		frameTime = static_cast<float>(glfwGetTime());
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
			deltaTime = static_cast<float>(glfwGetTime()) - frameTime;
			frameTime = static_cast<float>(glfwGetTime());
			renderer->setView(lookAt(camera->transform.getPos(), camera->transform.getPos() + camera->transform.forward(), camera->transform.up()));
			
			for (Entity* entity : entities)
				entity->update();
			update();

			renderer->beginDraw();

			for (Entity* entity : entities)
				entity->draw();

			renderer->endDraw();

			glfwPollEvents();
		}
	}
}