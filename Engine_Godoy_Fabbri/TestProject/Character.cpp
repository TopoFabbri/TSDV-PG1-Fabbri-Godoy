#include "Character.h"

using namespace ToToEng;

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

	if (ToToEng::Input::getKey(ToToEng::Input::a, Input::Repeated))
		accelerateInDir(-transform.right() * Time::getDelta());
	if (Input::getKey(Input::d, Input::Repeated))
		accelerateInDir(transform.right() * Time::getDelta());

	if (Input::getKey(Input::s, Input::Repeated))
		accelerateInDir(-transform.up() * Time::getDelta());
	if (Input::getKey(Input::w, Input::Repeated))
		accelerateInDir(transform.up() * Time::getDelta());

	if (Input::getKey(Input::q, Input::Repeated))
		transform.rotateZ(100.f * Time::getDelta());
	if (Input::getKey(Input::e, Input::Repeated))
		transform.rotateZ(-100.f * Time::getDelta());
	
	if (length(vel) > 0)
		vel = normalize(vel) * (length(vel) - friction);
}

void Character::accelerateInDir(vec3 dir)
{
	vel += dir * accel;

	if (length(vel) > maxSpeed)
		vel = normalize(vel) * maxSpeed;
}