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
void mergeSort(vector<T>&, int, int, bool (*compare)(const T&, const T&));

template <class T>
void merge(vector<T>&, int, int, int, bool (*compare)(const T&, const T&));

template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
	mergeSort(set, 0, set.size()-1, compare);
}

/*
FUNCTION: Recursive Merge Sort

Sorts the items within the vector using the merge sort algorithm.
*/
template <class T>
void mergeSort(vector<T>& set, int low, int high, bool (*compare)(const T&, const T&))
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;

		// Divide and conquer
		mergeSort(set, low, mid, compare);
		mergeSort(set, mid+1, high, compare);

		// Combine
		merge(set, low, mid, high, compare);
	}
}

/*
FUNCTION: Merge

Divides vector into subvectors. Proceeds to sort them and then merge the sorted subvectors.
*/
template <class T>
void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&))
{
	// Create temporary vector to hold merged subvectors
	vector<T> temp(high - low + 1);
	int i = low;      //subscript for start of left sorted subvector
	int j = mid+1;    //subscript for start of right sorted subvector
	int k = 0;        //subscript for start of merged vector

	// While not at the end of either subarray
	while (i <= mid && j <= high)
	{
		if (compare(set[j], set[i]))
		{
			temp[k] = set[j];
			++j;
			++k;
		}
		else
		{
			temp[k] = set[i];
			++i;
			++k;
		}
	}

	// Copy over any remaining elements of left subarray
	while (i <= mid)
	{
		temp[k] = set[i];
		++i;
		++k;
	}

	// Copy over any remaining elements of right subarray
	while (j <= high)
	{
		temp[k] = set[j];
		++j;
		++k;
	}

	// Copy merged elements back into original array
	for (i = 0, j = low; j <= high; i++, j++)
	set[j] = temp[i];
}
#endif
