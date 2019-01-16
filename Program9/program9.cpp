/***
ASSIGNMENT: Program 9 (Extra Credit)
PROGRAMMER: Afifah Arif
LOGON ID: XXXXXXXX
DUE DATE: 05/02/2018
FUNCTION: This program creates a series of classes to represent	some
	simple geometric shapes and a program to test your classes.
***/

#include <iostream>
#include <vector>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

int main(void)
{
	//Dynamically creates vector shapes
	std::vector <Shape *> shape(6);

	//Initializes vector with shapes
	shape.push_back(new Circle("green", 10));
	shape.push_back(new Rectangle("red", 8, 6));
	shape.push_back(new Triangle("yellow", 8, 4));
	shape.push_back(new Triangle("black", 4, 10));
	shape.push_back(new Circle("orange", 5));
	shape.push_back(new Rectangle("blue", 3, 7));

	std::cout << std::endl << "Printing all shapes..." << std::endl << std::endl;

	//Processes each element in vector 'shape'
	for(unsigned int i=0; i < shape.size(); ++i)
	{
		Shape *shapePtr = dynamic_cast<Shape *> (shape[i]);

		if(shapePtr != 0)
			shapePtr->print();
	}

	std::cout << std::endl << "Printing only triangles..." << std::endl << std::endl;

	for(unsigned int i=0; i < shape.size(); ++i)
	{
		Triangle *trianglePtr = dynamic_cast<Triangle *> (shape[i]);

		if(trianglePtr != 0)
			trianglePtr->print();
	}

	std::cout << std::endl;

	return 0;
}
