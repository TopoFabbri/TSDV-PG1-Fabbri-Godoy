#pragma once
#include <glm/vec2.hpp>
#include "Exports.h"

class TOTO_API Animation
{
private:
    float duration;
    glm::vec2 frameSize;
    glm::vec2 curOffset;
    float curTime;
    float frameTime;
    int frameQty;
    int curFrame;
    int animQty;
    int curAnim;
    int frameStart;
    int frameEnd;
    glm::vec2 startOffset;
    glm::vec2 maxOffset;
    
    void updateFrame();
    void updateOffset();

public:
    Animation(float duration, int frameQty, int animQty);
    Animation(float duration, int frameQty, int animQty, int frameStart, int frameEnd);
    ~Animation();

    void update();
    void setAnimByIndex(int animNumber);
    int getAnimIndex();
    
    glm::vec2 getOffset();
    glm::vec2 getFrameSize();

    void setStartOffset(glm::vec2 offset);
    void setMaxOffset(glm::vec2 offset);
};
