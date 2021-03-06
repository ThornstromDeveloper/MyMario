#include "Shapes.hpp"

Point::Point(float x, float y):
	x(x),
	y(y)
{ 
}

Point::Point():
	x(0),
	y(0)
{ 
}

Rectangle::Rectangle(float x, float y, int w, int h):
	x(x),
	y(y),
	w(w),
	h(h)
{
	this->update();
}

Rectangle::Rectangle():
	x(0),
	y(0),
	w(1),
	h(1)
{
	this->update();
}

Rectangle::Rectangle(Rectangle* other)
{
	this->copy(other);
}

void Rectangle::copy(Rectangle* other)
{
	this->x = other->x;
	this->y = other->y;
	this->w = other->w;
	this->h = other->h;

	this->update();
}

void Rectangle::update()
{
	this->top = y;
	this->bottom = y + h;

	this->leftmost = x;
	this->rightmost = x + w;

	this->center = Point(x + (w / 2), y + (h / 2));

	this->topLeft = Point(x, y);
	this->topRight = Point(x + w, y);
	this->bottomLeft = Point(x, y + h);
	this->bottomRight = Point(x + w, y + h);

	this->topCenter = Point(center.x, top);
	this->bottomCenter = Point(center.x, bottom);
	this->leftCenter = Point(leftmost, center.y);
	this->rightCenter = Point(rightmost, center.y);
}