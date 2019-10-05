#include "serendipity.h"
time_t b = time(NULL);

bookType lookUp(orderedLinkedList<bookType> & books){
	bookType book;
	string search;
	system("cls");
	cout << "************************************************************************************************" << endl;
	cout << "*                                        SERENDIPITY BOOKSELLERS                               *" << endl;
	cout << "************************************************************************************************" << endl;
	cout << "*  SEARCH: >";
	cin >> search;
	cin.ignore(100, '\n');
	cin.clear();
	string searchTemp = search;
	linkedListIterator<bookType> iterator;
	
	for(iterator = books.begin(); iterator != books.end(); ++iterator){
		
		bookType temp = *iterator;
		
		string bookTitleTemp = temp.getBookTitle(); 
		toUpper(bookTitleTemp);
		toUpper(searchTemp);
		//DEBUG LINES FOR SEEING COMPARISONS
		//cout << searchTemp  << "==" << bookTitleTemp <<endl;
		//system("pause");
		
		if(bookTitleTemp.find(searchTemp) != string::npos || temp.getISBN() == search)
		{
			cout << "Result>" << temp.getBookTitle() << endl;
			cout << "View This Record (y/n)? : " << endl;
			char c;
			cin >> c;
			if(c == 'y')
			{
				cout << temp;
				return temp;
			}
			
		}
	}
	return book;	
}