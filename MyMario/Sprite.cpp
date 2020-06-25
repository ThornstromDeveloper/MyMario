#include "Sprite.hpp"
#include "Shapes.hpp"
#include <iostream>

Sprite::Sprite(Window* window, std::string filename):
	window(window),
	filename(filename)
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

	//set this->clipRect to original image size
	this->crop(Rectangle(0, 0, this->width, this->height));
}

Sprite::~Sprite()
{
	if (this->image)
	{
		this->window->freeImage(this->image);
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

void Sprite::render(int x, int y)
{
}