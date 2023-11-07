#pragma once

#include "Entity.h"
#include "Exports.h"

namespace ToToEng
{
	class TOTO_API Entity2D :
		public Entity
	{
	private:
		vec2 uvOffset;
		vec2 uvScale;
		
	protected:
		void setOffset(vec2 offset);
		void setScale(vec2 scale);
		
	public:
		Entity2D(Renderer* renderer);
		~Entity2D() override;

		void updateVao() override;

		void draw() override;
	};
}