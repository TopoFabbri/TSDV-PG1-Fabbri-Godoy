#include "Character.h"

#include "Headers/GameTime.h"
#include "Headers/Input.h"

using namespace ToToEng;

Character::Character(Renderer* renderer) : Sprite(renderer)
{
    accel = 20.f;
    vel = vec3(0.f);
    maxSpeed = 4.f;
    friction = .1f;

    transform.setPos(vec3(0.f, 100.f, 0.f));

    addAnimation(1.f, 11, 9, "../res/textures/sonic.png", vec2(27.5f, 0.f));
    animation->setAnimByIndex(2);
}

Character::~Character()
{
}

void Character::update()
{
    Sprite::update();

    if (Input::getKey(Input::a, Input::Repeated))
    {
        accelerateInDir(-transform.right() * GameTime::getDelta());
        animation->setAnimByIndex(2);
    }
    if (Input::getKey(Input::d, Input::Repeated))
    {
        accelerateInDir(transform.right() * GameTime::getDelta());
        animation->setAnimByIndex(2);
    }

    if (Input::getKey(Input::s, Input::Repeated))
    {
        accelerateInDir(-transform.up() * GameTime::getDelta());
        animation->setAnimByIndex(2);
    }
    if (Input::getKey(Input::w, Input::Repeated))
    {
        accelerateInDir(transform.up() * GameTime::getDelta());
        animation->setAnimByIndex(2);
    }

    if (Input::getKey(Input::q, Input::Repeated))
        transform.rotateZ(100.f * GameTime::getDelta());
    if (Input::getKey(Input::e, Input::Repeated))
        transform.rotateZ(-100.f * GameTime::getDelta());

    if (Input::getKey(Input::f, Input::Pressed))
        animation->setAnimByIndex(animation->getAnimIndex() >= 7 ? 0 : animation->getAnimIndex() + 1);

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
