#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "sorts.h"

using std::cout;
using std::endl;
using std::fixed;
using std::ifstream;
using std::left;
using std::setprecision;
using std::setw;
using std::string;
using std::vector;

template <class T>
void quickSort(vector<T>& int, int, bool (*compare)(const T&, const T&));

template <class T>
int partition(vector<T>&, int, int, bool (*compare)(const T&, const T&));

template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
	quickSort(set, 0, set.size()-1, compare);
}

// Recursive quicksort function
template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&)
{
	int pivotPoint;
	if (start < end)
	{
		pivotPoint = partition(set, start, end, compare);     // Get the pivot point
		quickSort(set, start, pivotPoint - 1, compare);       // Sort first sublist
		quickSort(set, pivotPoint + 1, end, compare);         // Sort second sublist
	}
}

// Partition function
template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
	int pivotIndex, mid;
	T pivotValue, temp;
	mid = (start + end) / 2;
	temp = set[start];
	set[start] = set[mid];
	set[mid] = temp;
	pivotIndex = start;
	pivotValue = set[start];

	for (int scan = start + 1; scan <= end; ++scan)
	{
		if (compare(set[scan], pivotValue))
		{
			++pivotIndex;
			temp = set[pivotIndex];
			set[pivotIndex] = set[scan];
			set[scan] = temp;
		}
	}
	temp = set[start];
	set[start] = set[pivotIndex];
	set[pivotIndex] = temp;

	return pivotIndex;
}
