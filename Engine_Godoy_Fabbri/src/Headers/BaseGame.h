#pragma once

#include <list>

#include "Renderer.h"
#include "Shape.h"
#include "Exports.h"

namespace ToToEng
{
	class TOTO_API BaseGame
	{
	private:
		Window* window;

	protected:
		Renderer* renderer;
		std::list<Entity*> entities = std::list<Entity*>();

	public:
		BaseGame();
		virtual ~BaseGame();

		void run();

		virtual void update() = 0;
	};
}