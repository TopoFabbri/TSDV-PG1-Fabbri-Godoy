#pragma once

#include "Entity.h"
#include "Exports.h"

namespace ToToEng
{
	class TOTO_API Entity2D :
		public Entity
	{
	public:
		Entity2D(Renderer* renderer);
		~Entity2D() override;

		void draw() override;
	};
}