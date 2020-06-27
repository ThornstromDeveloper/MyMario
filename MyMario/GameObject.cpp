#include "GameObject.hpp"
#include "Shapes.hpp"

GameObject::GameObject(float x, float y, int w, int h)
{
	this->position = new Point(x, y);
	this->box = new Rectangle(x, y, w, h);
}

GameObject::~GameObject()
{
	delete this->position;
	delete this->box;
}