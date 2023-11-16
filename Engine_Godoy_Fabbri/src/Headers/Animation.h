#pragma once
#include <glm/vec2.hpp>

class Animation
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
    
    void updateFrame();
    void updateOffset();

public:
    Animation(float duration, int frameQty, int animQty);
    ~Animation();

    void update();
    void setAnimation(int animNumber);
    
    glm::vec2 getOffset();
    glm::vec2 getFrameSize();
};
