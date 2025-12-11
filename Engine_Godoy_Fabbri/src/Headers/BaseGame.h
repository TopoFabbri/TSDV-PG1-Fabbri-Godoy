#pragma once

#include <list>

#include "CollisionManager.h"
#include "Renderer.h"
#include "Exports.h"
#include "Input.h"
#include "TileMap.h"

namespace ToToEng
{
    class TOTO_API BaseGame
    {
    private:
        Window* window;
        CollisionManager* collisionManager;

    protected:
        Renderer* renderer;
        std::list<Entity*> entities = std::list<Entity*>();
        Camera* camera;
        TileMap* tileMap;

    public:
        BaseGame(bool is3D, int width, int height, const char* title);
        virtual ~BaseGame();

        void run();

        virtual void update() = 0;
    };
}
