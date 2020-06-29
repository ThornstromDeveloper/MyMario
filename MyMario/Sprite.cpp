#include "Sprite.hpp"
#include "Shapes.hpp"
#include <iostream>

Sprite::Sprite(Window* window, std::string filename):
	window(window),
	filename(filename),
	image(nullptr),
	clipRect(nullptr),
	width(0),
	height(0),
	flip(false)
{
	this->image = window->loadImage(this->filename);

	if (!this->image)
	{
		std::cout << "Sprite::load Failed on '" + this->filename + "'";
	}

	int w, h;
	SDL_QueryTexture(image, nullptr, nullptr, &w, &h);

	this->width = w;
	this->height = h;

	//set this->clipRect to original image
	this->crop(Rectangle(0, 0, this->width, this->height));
}

Sprite::~Sprite()
{
	if (this->image)
	{
		this->window->freeImage(this->image);
	}

	if (this->clipRect)
	{
		delete this->clipRect;
	}
}

void Sprite::crop(Rectangle rect)
{
	if (!this->clipRect)
	{
		this->clipRect = new Rectangle;
	}

	this->clipRect->copy(&rect);
}

void Sprite::render(int x, int y, bool flip)
{
	Rectangle destination(x, y, this->clipRect->w, this->clipRect->h);

	this->window->renderImage(this->image, this->clipRect, &destination, flip);
}

int Sprite::getWidth()
{
	return this->clipRect->w;
}

int Sprite::getHeight()
{
	return this->clipRect->h;
}