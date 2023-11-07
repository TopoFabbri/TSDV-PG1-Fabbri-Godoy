#pragma once
#include "Animation.h"
#include "Entity2D.h"

namespace ToToEng
{
    class TOTO_API Sprite :
        public Entity2D
    {
    private:
        unsigned int texture;
        Animation* animation;

    protected:
        void update() override;
        
    public:
        Sprite(Renderer* renderer);
        ~Sprite() override;
        
        void draw() override;
        void loadTexture(const char* filePath);
        void addAnimation(float duration, int frameQty, const char* filePath);
    };
}
