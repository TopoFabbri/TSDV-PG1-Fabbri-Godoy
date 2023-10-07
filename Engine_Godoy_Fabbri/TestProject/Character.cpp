#include "Character.h"

#include "Headers/GameTime.h"
#include "Headers/Input.h"

using namespace ToToEng;

Character::Character(Renderer* renderer) : Shape(renderer)
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
    if (Input::getKey(Input::a, Input::Repeated))
    accelerateInDir(-transform.right() * GameTime::getDelta());
    if (Input::getKey(Input::d, Input::Repeated))
        accelerateInDir(transform.right() * GameTime::getDelta());
    
    if (Input::getKey(Input::s, Input::Repeated))
        accelerateInDir(-transform.up() * GameTime::getDelta());
    if (Input::getKey(Input::w, Input::Repeated))
        accelerateInDir(transform.up() * GameTime::getDelta());
    
    if (Input::getKey(Input::q, Input::Repeated))
        transform.rotateZ(100.f * GameTime::getDelta());
    if (Input::getKey(Input::e, Input::Repeated))
        transform.rotateZ(-100.f * GameTime::getDelta());


    if (Input::getKey(Input::t, Input::Repeated))
    {
        if (getColor().x < 1.f)
            setColor(vec4((getColor().x + 0.05f), getColor().y, getColor().z,getColor().w));
    }
    if (Input::getKey(Input::r, Input::Repeated))
    {
        if (getColor().x > 0.f)
            setColor(vec4((getColor().x - 0.05f), getColor().y, getColor().z,getColor().w));
    }
    if (Input::getKey(Input::h, Input::Repeated))
    {
        if (getColor().y < 1.f)
            setColor(vec4(getColor().x, (getColor().y + 0.05f), getColor().z,getColor().w));
        
    }
    if (Input::getKey(Input::g, Input::Repeated))
    {
        if (getColor().y > 0.f)
            setColor(vec4(getColor().x, (getColor().y - 0.05f), getColor().z,getColor().w));
    }
    if (Input::getKey(Input::n, Input::Repeated))
    {
        if (getColor().z < 1.f)
            setColor(vec4(getColor().x, getColor().y, (getColor().z + 0.05f),getColor().w));
        
    }
    if (Input::getKey(Input::b, Input::Repeated))
    {
        if (getColor().z > 0.f)
            setColor(vec4(getColor().x, getColor().y, (getColor().z - 0.05f),getColor().w));
    }

    
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
