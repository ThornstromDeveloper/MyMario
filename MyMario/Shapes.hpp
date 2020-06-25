#ifndef SHAPES_HPP
#define SHAPES_HPP

class Point
{
public:
	float x;
	float y;

	Point();
	Point(float x, float y);
};

struct Rectangle
{
	float x;
	float y;
	int w;
	int h;

	float top;
	float bottom;
	float leftmost;
	float rightmost;

	Point center;
	Point leftCenter;
	Point rightCenter;
	Point topLeft;
	Point topRight;
	Point topCenter;
	Point bottomLeft;
	Point bottomRight;
	Point bottomCenter;

	Rectangle(float x, float y, int w, int h);
	Rectangle(Rectangle* other);
	Rectangle();
	void copy(Rectangle* other);
	void update();
};

#endif //SHAPES_HPP