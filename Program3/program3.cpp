/***
Program: CSCI 241 Program 3
Programmer: Afifah Arif
Logon ID: XXXXXXX
Due date: 02/28/18
Function: This program tests the functionality of the Verifier class.
***/

#include <iostream>
#include <string>
#include "Verifier.h"

using std::cout;
using std::endl;
using std::string;

#define NUM_FILES 7

int main()
{
Verifier v;
string fileName;

cout << "Sudoku Verifier\n";

for (int i = 1; i <= NUM_FILES; i++)
{
cout << endl;

// Construct file pathname
fileName = string("/home/turing/t90kjm1/CS241/Data/Spring2018/Assign3/solution")
+ (char)('0' + i) + ".txt";

// Read the solution file as input
v.readGrid(fileName.c_str());

// Print the Sudoku grid
v.printGrid();

// Verify whether or not the solution is correct
if (v.verifySolution())
cout << "\nThis is a valid Sudoku solution\n";
else
cout << "\nThis is not a valid Sudoku solution\n";
}

return 0;
}
