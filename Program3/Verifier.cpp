/*
Program: CSCI 241 Program 3
Programmer: Afifah Arif
Logon ID: XXXXXXXX
Due date: 02/28/18
*/

#include "Verifier.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;

/********************************
Function: Verifier()
Arguments: None
Returns: Nothing

Summary: Default constructor
********************************/
Verifier::Verifier()
{
	for (int rw = 0; rw < 9; rw++)
		for (int cl = 0; cl < 9; cl++)
	grid[rw][cl] = 0;
}

/**********************************************
Function: readGrid()
Arguments: char*
Returns: Nothing

Summary: Reads the contents of the input file
	 into the elemnts of the grid array
**********************************************/
void Verifier::readGrid(const char* File)
{
	std::ifstream inFile;
		inFile.open(File);
	for(int rw= 0; rw < 9; rw++)
	{
		for( int cl = 0; cl < 9; cl++)
		{
			inFile >> grid[rw][cl];
		}
	}
	inFile.close();
}

/********************************************
Function: printGrid()
Arguments: None
Returns: Nothing

Summary: Prints the Sudoku grid array to
	the screen as 9 rows of 9 columns
********************************************/
void Verifier::printGrid()
{
	int cCol = 0;
	int cRow = 0;

	cout << "-------------------------";
	for(int rw = 0; rw < 9; rw++)
	{
		std::cout << endl;
		cRow++;

		if(cRow == 4 || cRow == 7 || cRow == 10)
		{
			cout << "-------------------------" << endl;
			if(cRow == 10)
				cRow = 0;
		}
		cout << "| ";

		for(int cl = 0; cl < 9; cl++)
		{
			cCol++;
			cout << grid[rw][cl];
			cout << " ";

			if(cCol%3==0)
			{
				cout << "| ";
				if(cCol == 9)
				cCol = 0;
			}
		}
	}
	cout << endl << "-------------------------";
}

/***********************************************************
Function: verifySolution()
Arguments: None
Returns: True/False

Summary: Returns true if Soduko grid array contains
	a valid solution, false if not
***********************************************************/
bool Verifier::verifySolution()
{
	int i = 0, j = 0;

	for (int cl = 0; cl < 9; cl++)
		if (cl != j && grid[i][cl] == grid[i][j])
			return false;

	for (int rw = 0; rw < 9; rw++)
		if (rw != i && grid[j][rw] == grid[i][j])
			return false;

	for (int rw = (i/3) * 3; rw < (i/3) * 3 + 3; rw++)
		for (int cl = (j/3) * 3;  cl < (j/3) * 3 + 3; cl++)
			if (rw != i && cl != j && grid[rw][cl] == grid[i][j])
			return false;

	return true;
}
