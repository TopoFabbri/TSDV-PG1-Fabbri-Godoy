#include "BaseGame.h"

#include "CollisionManager.h"
#include "GameTime.h"
#include "Sprite.h"

namespace ToToEng
{
    BaseGame::BaseGame(bool is3D, int width, int height, const char* title)
    {
        camera = new Camera();
        window = new Window(width, height, title);
        renderer = new Renderer(window, camera, is3D);
        collisionManager = new CollisionManager();
        tileMap = nullptr;

        camera->transform.setPos({0, 0, 1});

        GameTime::resetTime();
    }

    BaseGame::~BaseGame()
    {
        delete renderer;
        delete window;
        delete camera;
        delete collisionManager;

        const int size = static_cast<int>(entities.size());

        for (int i = 0; i < size; i++)
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

            std::string newTitle = "Fps: " + std::to_string(1 / GameTime::getDelta()) + "  |  Frame Time: " + std::to_string(GameTime::getDelta());
            window->setTitle(newTitle.c_str());

            renderer->setView(lookAt(camera->transform.getPos(), camera->transform.getPos() + camera->transform.forward(), camera->transform.up()));

            for (Entity* entity : entities) entity->update();
            update();

            for (Entity* entityOne : entities)
            {
                bool newCollider = false;
                BoxCollider2D* colliderOne = dynamic_cast<Entity2D*>(entityOne)->collider;

                for (Entity* entityTwo : entities)
                {
                    if (entityOne == entityTwo)
                    {
                        newCollider = true;
                        continue;
                    }

                    if (!newCollider) continue;

                    BoxCollider2D* colliderTwo = dynamic_cast<Entity2D*>(entityTwo)->collider;

                    if (colliderOne && colliderTwo) CollisionManager::checkCollision(colliderOne, colliderTwo);
                }

                if (colliderOne)
                    tileMap->checkCollision(colliderOne);
            }

            renderer->beginDraw();

            for (Entity* entity : entities) entity->draw();

            if (tileMap) tileMap->draw();

            renderer->endDraw();

            glfwPollEvents();
        }
    }
}
