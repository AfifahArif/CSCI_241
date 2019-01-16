/***
PROGRAM: CSCI 241 Program 8, Part 1
PROGRAMMER: Afifah Arif
LOGON ID: XXXXXXXX
DUE DATE: 04/26/2018
FUNCTION: This program builds and sorts lists using the quick
	sort algorithm.
***/

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "sorts.h"

using std::cout;
using std::fixed;
using std::left;
using std::setprecision;
using std::string;
using std::vector;

// Data files
#define D1 "/home/turing/t90kjm1/CS241/Data/Spring2018/Assign8/data8a.txt"
#define D2 "/home/turing/t90kjm1/CS241/Data/Spring2018/Assign8/data8b.txt"
#define D3 "/home/turing/t90kjm1/CS241/Data/Spring2018/Assign8/data8c.txt"

// Output formatting constants
#define INT_SZ 4    // width of integer
#define FLT_SZ 7    // width of floating-pt number
#define STR_SZ 12   // width of string

#define INT_LN 15   // no of integers on single line
#define FLT_LN 9    // no of floating-pt nums on single line
#define STR_LN 5    // no of strings on single line

int main()
{
	vector<int> v1;      // vector of integers
	vector<float> v2;    // vector of floating-pt nums
	vector<string> v3;   // vector of strings

	// Print header message
	cout << "*** CSCI 241: Assignment 8 - Part 1 Output ***\n\n";

	// Build and print first list
	cout << "First list:\n\n";
	buildList(v1, D1);
	printList(v1, INT_SZ, INT_LN);

	// Build and print second list
	cout << fixed << setprecision(2);

	cout << "\nSecond list:\n\n";
	buildList(v2, D2);
	printList(v2, FLT_SZ, FLT_LN);

	// Build and print third list
	cout << left;

	cout << "\nThird list:\n\n";
	buildList(v3, D3);
	printList(v3, STR_SZ, STR_LN);

	// Print termination message
	cout << "\n*** End of program execution ***\n";

	return 0;
}
