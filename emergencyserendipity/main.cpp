
#include "serendipity.h"



int main() {
	
	string bookTitle[20];
	string isbn[20];
	string author[20];
	string publisher[20];
	string dateAdded[20];
	int qtyOnHand[20];
	double wholesale[20];
	double retail[20];
	int bookCount = 0;
	
	
    mainMenu(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, bookCount);
	//bookInfo();
    return 0;
}