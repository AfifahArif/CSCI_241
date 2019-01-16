#include <iostream>
#include <string>
#include "Triangle.h"

/*
FUNCTION: Rectangle()

USE: Default constructor for Rectangle class.It takes color,
	height, and width of a rectangle.

ARGUMENTS:
	1. string triC - sent to shape class for initialization
	2. int triH -  stored in private variable 'height'
	3. int triB - stored in the private variable 'base'
*/
Triangle::Triangle(std::string triC, int triH, int triB):Shape(triC)
{
	h = triH;
	b = triB;
}

/*
FUNCTION: get_area()

USE: Calculates area of triangle base on 'height' and 'width' variables.
	No arguements. Returns double.
*/
double Triangle::get_area()
{
	double area = 0.0;
	area = (0.5*b*h);

	return area;
}

/*
FUNCTION: print()

USE: Calls class 'Shape' for color to be printed, then it prints
	the triangle height, base, and area. No arguments.
*/
void Triangle::print()
{
	Shape::print();
	std::cout << " triangle, height " << h << ", base " << b << ", area " << get_area() << std::endl;
}
