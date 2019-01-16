#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <string>
#include "Shape.h"

class Rectangle:public Shape
{
	protected:
		int h;
		int w;

	public:
		Rectangle(std::string, int, int);
		virtual double get_area();
		virtual void print();
};
#endif
