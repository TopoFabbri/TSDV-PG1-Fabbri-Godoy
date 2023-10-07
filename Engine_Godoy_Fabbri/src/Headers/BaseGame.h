#pragma once

#include <list>

#include "Renderer.h"
#include "Shape.h"
#include "Exports.h"
#include "Input.h"
#include "GameTime.h"

namespace ToToEng
{
	class TOTO_API BaseGame
	{
	private:
		Window* window;

	protected:
		Renderer* renderer;
		std::list<Entity*> entities = std::list<Entity*>();
		Camera* camera;

	public:
		BaseGame(bool is3D, int width, int height, const char* title);
		virtual ~BaseGame();

		void run();

		virtual void update() = 0;
	};
}