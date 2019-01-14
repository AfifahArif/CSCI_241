#ifndef BOOK_H
#define BOOK_H

class Book
{
	private:
		char isbn[11]{};
		char title[41]{};
		double price;
		int quantity;
    
	// Data members and method prototypes for the Book class go here
	public:
	Book();
	Book(char*, char*, double, int);
		const char* getISBN() const;
		const char* getTitle();
		double getPrice();
		int getQuantity();
		void setPrice(double);
		void setQuantity(int);
		int  fulfillOrder(int);
		void print();
};
#endif
