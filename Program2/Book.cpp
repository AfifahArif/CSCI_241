#include <iostream>
#include <iomanip>
#include <cstring>
#include "Book.h"

using std::left;
using std::string;
using std::endl;
using std::setprecision;
using std::strcpy;
using std::setw;
using std::cout;

//defaults the constructors
Book::Book()
{
	setPrice(0);
	setQuantity(0);
}

//sets the constructors
Book::Book(char ISBN[11], char Title [41], double Price, int Quantity)
{
	strcpy(isbn,ISBN);
	strcpy(title, Title);
	setPrice(Price);
	setQuantity(Quantity);
}

//returns the ISBN value
const char* Book::getISBN() const
{
	return isbn;
}

//returns the Title value
const char* Book::getTitle()
{
	return title;
}

//returns the Price value
double Book::getPrice()
{
	return price;
}

//returns the Quantity value
int Book::getQuantity()
{
	return quantity;
}

//Sets the price for the classes
void Book::setPrice(double Price)
{
	if (Price >= 0)
	{
		price = Price;
	}
	else
	{
		price = 0;
	}
}

//sets the quantity for the classes
void Book::setQuantity(int Quantity)
{
	if (Quantity >= 0)
	{
		quantity = Quantity;
	}
	else
	{
		Quantity = 0;
	}
}

//checks to see if the order can be completed and sets a new quantity
int  Book::fulfillOrder(int i)
{
	int y;

	if (i <= 0)
	{
		y = 0;
	}
	else if (i <= quantity)
	{
		y=i;
		quantity=quantity-i;
	}
	else
	{
		y = quantity;
		quantity=0;
	}
	return y;
}

//displays the values of each books
void Book::print()
{
	cout << left << setw(14) << isbn;
	cout << left << setw(44) << title;
	cout << left << setw(10) << price;
	cout << left << quantity;
}
