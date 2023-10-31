#pragma once
#include "Entity2D.h"

namespace ToToEng
{
    class TOTO_API Sprite :
        public Entity2D
    {
    public:
        Sprite(Renderer* renderer);
        ~Sprite() override;
    };
}
