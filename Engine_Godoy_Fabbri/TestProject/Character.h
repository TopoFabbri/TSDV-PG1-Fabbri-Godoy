#pragma once
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

public:
    explicit Character(ToToEng::Renderer* renderer);
    ~Character() override;

    void update() override;

    void accelerateInDir(vec3 dir);
};
