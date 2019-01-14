//Tests class

#include <iostream>
#include "BookStore.h"
#include <fstream>
#include <cstring>
#include <iomanip>

using std::cout;
using std::endl;
using std::cerr;
using std::ifstream;
using std::cout;
using std::string;

int main()
{
	BookStore store("bookdata");
	store.print();
	store.processOrders("orders.txt");
	store.print();
}
