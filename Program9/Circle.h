#ifndef CIRCLE_H
#define CIRCLE_H
#include <string>
#include "Shape.h"

class Circle:public Shape
{
	protected:
		int r;

	public:
		Circle(std::string, int);
		virtual double get_area();
		virtual void print();
};
#endif
