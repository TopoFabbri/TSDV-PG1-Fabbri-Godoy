#include "Animation.h"

#include "GameTime.h"

void Animation::updateFrame()
{
    curFrame = static_cast<int>(curTime * static_cast<float>(frameQty) / duration) - 1;
}

void Animation::updateOffset()
{
    curOffset = static_cast<float>(curFrame) * frameWidth;
}

Animation::Animation(float duration, int frameQty)
{
    this->duration = duration;
    this->frameQty = frameQty;

    frameWidth = 1.f / static_cast<float>(frameQty);
    curOffset = 0;
    curTime = 0;
    frameTime = duration / static_cast<float>(frameQty);
    curFrame = 0;
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

float Animation::getFrameWidth()
{
    return frameWidth;
}

float Animation::getOffset()
{
    return curOffset;
}
