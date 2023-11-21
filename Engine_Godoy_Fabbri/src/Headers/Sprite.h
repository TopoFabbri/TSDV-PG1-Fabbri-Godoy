#pragma once
#include "Animation.h"
#include "Entity2D.h"

namespace ToToEng
{
    class TOTO_API Sprite :
        public Entity2D
    {
    public:
        unsigned int texture;

    protected:
        void update() override;
        
    public:
        Animation* animation;
        bool playAnim = true;
        
        Sprite(Renderer* renderer);
        ~Sprite() override;
        
        void draw() override;
        void loadTexture(const char* filePath);
        void addAnimation(float duration, int frameQty, int animQty, const char* filePath);
        void addAnimation(float duration, int frameQty, int animQty, const char* filePath, int frameStart, int frameEnd);
    };
}
