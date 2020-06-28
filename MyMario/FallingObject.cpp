#include "FallingObject.hpp"
#include "Shapes.hpp"

FallingObject::FallingObject(float x, float y, int w, int h):
	GameObject(x, y, w, h),
	desiredPosition(nullptr)
{
	this->desiredPosition = new Rectangle();
}

FallingObject::~FallingObject()
{
	delete this->desiredPosition;
}

void FallingObject::preUpdate(float dt)
{
	this->desiredPosition->copy(this->box);
}