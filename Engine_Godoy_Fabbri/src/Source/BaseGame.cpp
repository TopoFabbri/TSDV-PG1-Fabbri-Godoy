#include "BaseGame.h"

namespace ToToEng
{
	BaseGame::BaseGame(bool is3D, int width, int height, const char* title)
	{
		camera = new Camera();
		window = new Window(width, height, title);
		renderer = new Renderer(window, camera, is3D);
		collisionManager = new CollisionManager();

		camera->transform.setPos({ 0, 0, 1 });

		GameTime::resetTime();
	}

	BaseGame::~BaseGame()
	{
		delete renderer;
		delete window;
		delete camera;
		delete collisionManager;

		for (int i = 0; i < static_cast<int>(entities.size()); i++)
		{
			const Entity* tmp = entities.front();
			entities.pop_front();
			delete tmp;
		}

		entities.clear();
	}

	void BaseGame::run()
	{
		while (!window->shouldClose())
		{
			GameTime::update();
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

	void BaseGame::DoCollisions()
	{
		for(auto it = entities.begin(); it != entities.end(); ++it)
		{
			for(auto jt = std::next(it); jt != entities.end(); ++jt)
			{
				if(collisionManager->checkCollision(**it, **jt))
				{
					std::cout<< "Collision" << std::endl;
					
				}
			}
		}
	}
}
