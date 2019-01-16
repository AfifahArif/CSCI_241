#ifndef SORTS_H
#define SORTS_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>

using std::cout;
using std::endl;
using std::fixed;
using std::ifstream;
using std::left;
using std::setprecision;
using std::setw;
using std::string;
using std::vector;

/*
FUNCTION: Sort

Reads a series of items from an input file, and then prints the items.Also c$
*/
template <class T>
void buildList(vector<T>& set, const char* fileName)
{
	T item;
	ifstream inFile;
	inFile.open(fileName);

	if (!inFile)
	{
		cout << "Unable to open input file " << fileName << endl;
		exit(1);
	}

	inFile >> item;
	while (inFile)
	{
		set.push_back(item);
		inFile >> item;
	}
	inFile.close();
}

/*
FUNCTION: printList

Prints a list of items stored in a vector
*/
template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
{
	int i = 0;

	while (i < (int) set.size())
	{
		cout << setw(itemWidth) << set[i] << ' ';
		i++;

		if (i % numPerLine == 0)
		cout << endl;
	}

	if (i % numPerLine != 0)
	cout << endl;
}

/*
FUNCTION: lessThan

Returns "true" if item1 is less thank item2. It this is not the case, returns false
*/
template <class T>
bool lessThan(const T& item1, const T& item2)
{
	if (item1 < item2)
		return true;

	else
		return false;
}

/*
FUNCTION: greaterThan

Returns "true" if item1 is greater than item2. If this is not the case, returns false
*/
template <class T>
bool greaterThan(const T& item1, const T& item2)
{
	if (item1 > item2)
		return true;

	else
		return false;
}
#endif
