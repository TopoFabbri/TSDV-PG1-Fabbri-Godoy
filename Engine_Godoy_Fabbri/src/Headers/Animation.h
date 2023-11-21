#pragma once
#include <glm/vec2.hpp>
#include "Exports.h"

class TOTO_API Animation
{
private:
    float duration;
    glm::vec2 frameSize;
    glm::vec2 curOffset;
    glm::vec2 animOffset;
    float curTime;
    float frameTime;
    int frameQty;
    int curFrame;
    int animQty;
    int curAnim;
    
    void updateFrame();
    void updateOffset();

public:
    Animation(float duration, int frameQty, int animQty, glm::vec2 offset);
    ~Animation();

    void update();
    void setAnimByIndex(int animNumber);
    int getAnimIndex();
    
    glm::vec2 getOffset();
    glm::vec2 getFrameSize();
};
