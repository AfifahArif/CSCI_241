#include <iostream>
#include <string>
#include "Shape.h"

/***
FUNCTION: Shape()

USE: Default constructor which initializes shapes color.
***/
Shape::Shape(const std::string& shapeC):color(shapeC) {}

/***
FUNCTION: print()

USE: Prints the color stored in the 'color' string. No arguements.
***/
void Shape::print()
{
	std::cout << color;
}
