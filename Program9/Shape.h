#ifndef SHAPE_H
#define SHAPE_H
#include <string>

class Shape
{
	protected:
		std::string color;

	public:
		Shape(const std::string&);
		virtual double get_area() = 0;
		virtual void print();
};
#endif
