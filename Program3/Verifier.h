#ifndef VERIFIER_H
#define VERIFIER_H

/*
Program: CSCI 241 Program 3
Programmer: Afifah Arif
Logon ID: XXXXXXX
Due date: 02/28/18
Function: Contains the declaration for the Verifier class.
*/

class Verifier
{
	private:
		char grid[9][9];

	public:
		Verifier();
		void readGrid(const char*);
		void printGrid();
		bool verifySolution();
};
#endif
