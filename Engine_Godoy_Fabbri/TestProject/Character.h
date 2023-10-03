#pragma once
#include "Headers/Shape.h"
#include "Headers/Input.h"
#include "Headers/Time.h"

class Character :
    public ToToEng::Shape
{
private:
    float accel;
    vec3 vel;
    float maxSpeed;
    float friction;

public:
    Character(ToToEng::Renderer* renderer);
    ~Character() override;

    void update() override;

    void accelerateInDir(vec3 dir);
};