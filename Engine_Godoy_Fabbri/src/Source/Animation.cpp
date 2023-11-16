#include "Animation.h"

#include "GameTime.h"

void Animation::updateFrame()
{
    curFrame = static_cast<int>(curTime * static_cast<float>(frameQty) / duration) - 1;
}

void Animation::updateOffset()
{
    curOffset.x = static_cast<float>(curFrame) * frameSize.x;
    curOffset.y = static_cast<float>(curAnim) * frameSize.y;
}

Animation::Animation(float duration, int frameQty, int animQty)
{
    this->duration = duration;
    this->frameQty = frameQty;
    this->animQty = animQty;
    
    frameSize.x = 1.f / static_cast<float>(frameQty);
    frameSize.y = 1.f / static_cast<float>(animQty);
    
    curOffset.x = 0;
    curOffset.y = 0;
    curTime = 0;
    frameTime = duration / static_cast<float>(frameQty);
    curFrame = 0;
    curAnim = 0;
}

Animation::~Animation()
{
}

void Animation::update()
{
    curTime += ToToEng::GameTime::getDelta();

    while (curTime >= duration)
        curTime -= duration;
        
    updateFrame();
    updateOffset();
}

void Animation::setAnimation(int animNumber)
{
    curAnim = animNumber;
}

glm::vec2 Animation::getOffset()
{
    return curOffset;
}

glm::vec2 Animation::getFrameSize()
{
    return frameSize;
}
