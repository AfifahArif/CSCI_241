#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include <string>
#include "Book.h"

using std::string;

class BookStore
{
	private:
		Book books[30];
		int sumBooks = 0;
		void sortByISBN();
		int searchForISBN(const char*) const;

	// Data members and method prototypes for the Book class go here
	public:
		BookStore();
		BookStore(const string&);
		void processOrders(const string&);
		void print();
};
#endif
