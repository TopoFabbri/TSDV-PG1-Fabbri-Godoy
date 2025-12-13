#pragma once

#include "BoxCollider2D.h"
#include "Entity.h"
#include "Exports.h"

namespace ToToEng
{
	class TOTO_API Entity2D :
		public Entity
	{
	public:
		vec2 uvOffset;
		vec2 uvScale;
		
		bool getIsTrigger();
		Entity2D(const Entity2D& other);
		
		Entity2D& operator=(const Entity2D& other);
		
		void setOffset(vec2 offset);
		void setScale(vec2 scale);
		
		BoxCollider2D* collider;
		
		Entity2D(Renderer* renderer);
		~Entity2D() override;

		void updateVao() override;

		void draw() override;

		void setTrigger(bool isTrigger);
	};
}