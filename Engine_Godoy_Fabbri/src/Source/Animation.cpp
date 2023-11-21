#include "Animation.h"

#include "GameTime.h"

void Animation::updateFrame()
{
    curFrame = static_cast<int>(curTime / frameTime) + frameStart;
}

void Animation::updateOffset()
{
    curOffset.x = static_cast<float>(curFrame) * frameSize.x + startOffset.x;
    curOffset.y = static_cast<float>(curAnim) * frameSize.y + startOffset.y;
}

Animation::Animation(float duration, int frameQty, int animQty)
{
    this->duration = duration;
    this->frameQty = frameQty;
    this->animQty = animQty;

    frameStart = 0;
    frameEnd = frameQty;
    
    frameSize.x = 1.f / static_cast<float>(frameQty);
    frameSize.y = 1.f / static_cast<float>(animQty);
    
    curOffset.x = 0;
    curOffset.y = 0;
    curTime = 0;
    frameTime = duration / static_cast<float>(frameQty - frameStart - (frameQty - frameEnd));
    curFrame = 0;
    curAnim = 0;

    startOffset = glm::vec2(0);
    maxOffset = glm::vec2(0);
}

Animation::Animation(float duration, int frameQty, int animQty, int frameStart, int frameEnd)
{
    this->duration = duration;
    this->frameQty = frameQty;
    this->animQty = animQty;
    this->frameStart = frameStart;
    this->frameEnd = frameEnd;
    
    frameSize.x = 1.f / static_cast<float>(frameQty);
    frameSize.y = 1.f / static_cast<float>(animQty);
    
    curOffset.x = 0;
    curOffset.y = 0;
    curTime = 0;
    frameTime = duration / static_cast<float>(frameQty - frameStart - (frameQty - frameEnd));
    curFrame = 0;
    curAnim = 0;

    startOffset = glm::vec2(0);
    maxOffset = glm::vec2(0);
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

void Animation::setAnimByIndex(int animNumber)
{
    if (animNumber >= 0 && animNumber < animQty)
        curAnim = animNumber;
}

int Animation::getAnimIndex()
{
    return curAnim;
}

glm::vec2 Animation::getOffset()
{
    return curOffset;
}

glm::vec2 Animation::getFrameSize()
{
    return frameSize;
}

void Animation::setStartOffset(glm::vec2 offset)
{
    startOffset = offset;

    frameSize.x = (1.f - startOffset.x) / static_cast<float>(frameQty);
    frameSize.y = (1.f - startOffset.y) / static_cast<float>(animQty);
}

void Animation::setMaxOffset(glm::vec2 offset)
{
    maxOffset = offset;
        
    frameSize.x = (1.f - startOffset.x - maxOffset.x) / static_cast<float>(frameQty);
    frameSize.y = (1.f - startOffset.y - maxOffset.y) / static_cast<float>(animQty);
}
