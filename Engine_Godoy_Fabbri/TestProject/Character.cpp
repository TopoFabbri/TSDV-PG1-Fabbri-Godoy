#include "Character.h"

#include <algorithm>
#include <complex>

#include "Headers/GameTime.h"
#include "Headers/Input.h"

using namespace ToToEng;

Character::Character(Renderer* renderer) : Sprite(renderer)
{
    accel = 20000.f;
    vel = vec3(0.f);
    maxSpeed = 200.f;
    friction = .1f;
    rotSpeed = 400.f;

    transform.setPos(vec3(0.f, 20.f, .5f));
    
    addAnimation(.5f, 2, {0, 16.f * 7}, {16.f, 16.f}, "../res/maps/Battle City Atlas.png");
    setTrigger(false);
}

Character::~Character()
{
}

void Character::move()
{
    
    if (!hasAccelerated)
    {
        const float t = std::min(friction, 1.0f);
        vel = vel * (1.0f - t) + vec3(0.f) * t;
    }
    
    transform.setPos(transform.getPos() + vel * GameTime::getDelta());
    
    if (length(vel) > 0)
        playAnim = true;
    else
        playAnim = false;
}

void Character::update()
{
    Sprite::update();

    hasAccelerated = false;
    
    if (Input::getKey(Input::a, Input::Repeated))
        accelerateInDir(-transform.right() * GameTime::getDelta());
    if (Input::getKey(Input::d, Input::Repeated))
        accelerateInDir(transform.right() * GameTime::getDelta());
    
    if (Input::getKey(Input::s, Input::Repeated))
        accelerateInDir(-transform.up() * GameTime::getDelta());
    if (Input::getKey(Input::w, Input::Repeated))
        accelerateInDir(transform.up() * GameTime::getDelta());
    
    if (Input::getKey(Input::left, Input::Repeated))
        transform.rotateZ(rotSpeed * GameTime::getDelta());
    if (Input::getKey(Input::right, Input::Repeated))
        transform.rotateZ(-rotSpeed * GameTime::getDelta());
    
    move();
}

void Character::accelerateInDir(vec3 dir)
{
    if (length(dir) <= 0) return;
    
    hasAccelerated = true;
    
    vel += dir * accel * GameTime::getDelta();

    if (length(vel) > maxSpeed)
        vel = normalize(vel) * maxSpeed;
}
