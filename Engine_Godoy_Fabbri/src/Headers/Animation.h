#pragma once

class Animation
{
private:
    float duration;
    float frameWidth;
    float curOffset;
    float curTime;
    float frameTime;
    int frameQty;
    int curFrame;
    
    void updateFrame();
    void updateOffset();

public:
    Animation(float duration, int frameQty);
    ~Animation();

    void update();
    float getOffset();
    float getFrameWidth();
};
