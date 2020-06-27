#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "Shapes.hpp"

class GameObject
{
    public:
        GameObject(float x = 0.0, float y = 0.0, int w = 0, int h = 0);
        ~GameObject();

        Point* position;
        Rectangle* box;
};

#endif //GAMEOBJECT_HPP