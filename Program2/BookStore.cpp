#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "BookStore.h"

using std::ifstream;
using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::ios;
using std::setw;
using std::right;

//This function sets the variable equal to a default value.
BookStore::BookStore()
{
	sumBooks = 0;
}

//This function opens, reads and closes the file.
BookStore::BookStore(const string& file)
{
	ifstream inFile(file);

	if (!inFile)
	{
	cerr<<"Error - unable to open file" <<endl;
	exit(1);
	}

	inFile.read((char*) this, sizeof(BookStore));
	inFile.close();
	sortByISBN();
}

//This function prints the books filed in the array.
void BookStore::print()
{
	cout << endl;
	cout << "Book Inventory Listing" << endl;
	cout << endl;
	cout << "ISBN " << right  <<  setw(14)<< " Title " <<  setw(44) << "Price " << setw(5) <<  "Qty " << setw(6) << endl;

int i;
	for (i = 0; i < sumBooks; i++)
	{
		books[i].print();
		cout << endl;
	}
}

//This function sorts ISBN numbers by descending order.
void BookStore::sortByISBN()
{
	int x,y;
	Book bucket;

	for(x = 1; x < sumBooks; x++)
	{
		bucket = books[x];

		for(y = x; (y > 0) && (strcmp(books[y-1].getISBN(), bucket.getISBN()) > 0); y--)
		{
			books[y] = books[y-1];
		}
		books[y] = bucket;
	}
}

//This function figures out if an ISBN that the user is looking for is in the ISBN  list.
int BookStore::searchForISBN(const char* isbn) const
{
	int low = 0;
	int high = sumBooks - 1;
	int mid;

	while(low <= high)
	{
		mid = (low + high)/2;

		if (strcmp(isbn, books[mid].getISBN()) == 0)
		{
			return mid;
		}
		if (strcmp(isbn,books[mid].getISBN()) < 0)
		{
			high = mid -1;
		}
		else
		{
		low = mid +1;
		}
	}
	return -1;
}

//This function takes the order from the list & compares it to whether or not you have them.
void BookStore::processOrders(const string& orders)
{
	char orderNumber[7];
	char isbn[11];
	int orderQuantity;
	int numShipped;

	ifstream inFile(orders);

	if (!inFile)
	{
		cerr<<"Error - unable to open file" <<endl;
		exit(1);
	}
	cout << endl;
	cout << "Order Listing" << endl;
	cout << endl;
	while (inFile >> orderNumber)
	{
		inFile >> isbn;
		inFile >> orderQuantity;

		int index = searchForISBN(isbn);

		if(index == -1)
		{
			cout << "There is an error" << endl;
		}
		else
		{
			numShipped = books[index].fulfillOrder(orderQuantity);
		cout << "Order No. " << right <<  orderNumber << " : ISBN " << isbn << ", " << numShipped << right << "of " <<orderQuantity << "Shipped, order total $" << (numShipped * books[index].getPrice()) << endl;
		}
	}
	inFile.close();
}
