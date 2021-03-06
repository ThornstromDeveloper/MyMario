#include "Animation.hpp"
#include "Sprite.hpp"

Animation::Animation(Window* window, Rectangle* selected_box, std::string filename, int amount, int framerate, bool flip, int loops):
	Sprite(window, filename),
	framerate(framerate),
	curFrame(0),
	maxFrame(amount),
	loops(loops),
	timesLooped(0)
{
	int source_x = selected_box->x;
	int source_y = selected_box->y;
	int frameW = selected_box->w / amount;
	int frameH = selected_box->h;

	this->flip = flip;

	//set part of image to display
	this->crop(Rectangle(source_x, source_y, frameW, frameH));
}

void Animation::update(float dt)
{
	this->timer.pause();

	//updating amount of frames to skip since last update
	int time_between_frames = (1000 / this->framerate); // milisseconds
	int frames_passed = this->timer.delta() / time_between_frames;

	if (frames_passed == 0)
	{
		timer.unpause();
		return;
	}

	for (int i = 0; i < frames_passed; i++)
	{
		this->nextFrame();
	}

	this->crop(Rectangle(this->clipRect->x, this->clipRect->y, this->clipRect->w, this->clipRect->h));

	this->timer.restart();
}

void Animation::nextFrame()
{
	this->curFrame++;
	this->clipRect->x += this->clipRect->w;

	if (this->curFrame >= this->maxFrame)
	{
		this->firstFrame();
	}
}

void Animation::firstFrame()
{
	this->curFrame = 0;
	this->clipRect->x = 0;

	//if -1 it will repeat forever
	if (this->loops != -1)
	{
		this->timesLooped++;
	}
}

void Animation::start()
{
	this->curFrame = 0;
	this->timesLooped = 0;
	this->timer.start();
}

void Animation::stop()
{
	this->timer.stop();
}