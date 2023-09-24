#include "Transform.h"

void Transform::updateTransformMatrix()
{
	transformMatrix = posMat * rotMat * scaleMat;
}

Transform::Transform()
{
	setPos({ 0.0f, 0.0f, 0.0f });
	setScale({ 1.0f, 1.0f, 1.0f });
	setRot({ 0.0f, 0.0f, 0.0f });
	rotMat = mat4(1.0f);

	updateTransformMatrix();
}

Transform::~Transform()
{
}

vec3 Transform::getPos()
{
	return pos;
}

vec3 Transform::getScale()
{
	return scale;
}

vec3 Transform::getRot()
{
	return rot;
}

mat4 Transform::getTransformMatrix()
{
	return transformMatrix;
}

vec3 Transform::up()
{
	return vec3(transformMatrix[1][0], transformMatrix[1][1], transformMatrix[1][2]);
}

vec3 Transform::right()
{
	return glm::vec3(transformMatrix[0][0], transformMatrix[0][1], transformMatrix[0][2]);
}

vec3 Transform::forward()
{
	return glm::vec3(-transformMatrix[2][0], -transformMatrix[2][1], -transformMatrix[2][2]);
}

void Transform::setPos(const vec3& v)
{
	pos = v;

	posMat = mat4(1.f);

	translateX(v.x);
	translateY(v.y);
	translateZ(v.z);

	updateTransformMatrix();
}

void Transform::translateX(float x)
{
	pos.x += x;

	posMat = translate(posMat, vec3(x, 0.f, 0.f));

	updateTransformMatrix();
}

void Transform::translateY(float y)
{
	pos.y += y;

	posMat = translate(posMat, vec3(0.f, y, 0.f));

	updateTransformMatrix();
}

void Transform::translateZ(float z)
{
	pos.z += z;

	posMat = translate(posMat, vec3(0.f, 0.f, z));

	updateTransformMatrix();
}

void Transform::setScale(const vec3& v)
{
	scale = v;

	scaleMat = mat4(1.f);

	scaleMat = glm::scale(scaleMat, scale);

	updateTransformMatrix();
}

void Transform::setScaleX(float x)
{
	scale.x = x;

	scaleMat = glm::scale(scaleMat, scale);

	updateTransformMatrix();
}

void Transform::setScaleY(float y)
{
	scale.y = y;

	scaleMat = glm::scale(scaleMat, scale);

	updateTransformMatrix();
}

void Transform::setScaleZ(float z)
{
	scale.z = z;

	scaleMat = glm::scale(scaleMat, scale);

	updateTransformMatrix();
}

void Transform::setRot(const vec3& v)
{
	rot = v;

	rotMat = mat4(1.f);

	rotateX(v.x);
	rotateY(v.y);
	rotateZ(v.z);

	updateTransformMatrix();
}

void Transform::rotateX(float x)
{
	rot.x += x;

	rotMat = rotate(rotMat, radians(x), vec3(1.f, 0.f, 0.f));

	updateTransformMatrix();
}

void Transform::rotateY(float y)
{
	rot.y += y;

	rotMat = rotate(rotMat, radians(y), vec3(0.f, 1.f, 0.f));

	updateTransformMatrix();
}

void Transform::rotateZ(float z)
{
	rot.z += z;

	rotMat = rotate(rotMat, radians(z), vec3(0.f, 0.f, 1.f));

	updateTransformMatrix();
}