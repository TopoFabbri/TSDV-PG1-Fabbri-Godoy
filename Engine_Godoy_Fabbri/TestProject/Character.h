#pragma once
#include <vector>

#include "Headers/Sprite.h"

class Character :
    public ToToEng::Sprite
{
private:
    float accel;
    vec3 vel;
    float maxSpeed;
    float friction;
    float rotSpeed;
    
    bool hasAccelerated;
    
    std::vector<vec2> animOffsets;

public:
    explicit Character(ToToEng::Renderer* renderer);
    ~Character() override;
    void move();

    void update() override;

    void accelerateInDir(vec3 dir);
};
