#ifndef FALLINGOBJECT_HPP
#define FALLINGOBJECT_HPP

#include "GameObject.hpp"

class FallingObject: public GameObject
{
	public:
		FallingObject(float x, float y, int w, int h);
		virtual ~FallingObject();

		Rectangle* desiredPosition;
};

#endif //FALLINGOBJECT_HPP