/***
PROGRAMMER: Afifah Arif
PURPOSE: File contains declaration of Triangle
	class from shape using public inheritance.
***/

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <string>
#include "Shape.h"

class Triangle:public Shape
{
	protected:
		int h;
		int b;

	public:
		Triangle(std::string, int, int);
		virtual double get_area();
		virtual void print();
};
#endif
