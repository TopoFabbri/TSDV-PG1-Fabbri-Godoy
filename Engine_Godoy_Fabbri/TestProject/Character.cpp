#include "Character.h"

Character::Character(ToToEng::Renderer* renderer) : Shape(renderer)
{
    accel = 20.f;
    vel = vec3(0.f);
    maxSpeed = 4.f;
    friction = .1f;
}

Character::~Character()
{
}

void Character::update()
{
    transform.setPos(transform.getPos() + vel);

    if (length(vel) > 0)
        vel = normalize(vel) * (length(vel) - friction);
}

void Character::accelerateInDir(vec3 dir)
{
    vel += dir * accel;

    if (length(vel) > maxSpeed)
        vel = normalize(vel) * maxSpeed;
}
