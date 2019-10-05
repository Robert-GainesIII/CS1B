#include "serendipity.h"

//displays a meny that shows the user the different options they can chose from
void invMenu(string bookTitle[], string isbn[], string author[], string publisher[], string dateAdded[], int qtyOnHand[], double wholesale[], 
double retail[], int &bookCount){
    char choice = ' ';

    do{
		
		system("cls");
		cout << "***************************************" << endl;
        cout << "*     Serendipity Booksellers         *" << endl;
        cout << "*       Inventory Database            *" << endl;
		cout << "*                                     *" << endl;
        cout << "* <1> Look Up a Book                  *" << endl;
        cout << "* <2> Add a Book                      *" << endl;
        cout << "* <3> Edit a Book's Record            *" << endl;
        cout << "* <4> Delete a Book                   *" << endl;
        cout << "* <5> Return to Main Menu             *" << endl;
		cout << "***************************************" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
            case '1':
                //lookUpBook();
				system("pause");
                break;
            case '2':
                addBook(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, bookCount);
				system("pause");
                break;
            case '3':
                editBook();
				system("pause");
                break;
            case '4':
                deleteBook();
				system("pause");
                break;
            case '5':
				mainMenu(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, bookCount);
                break;
            default:
                cout << "Please enter a range between 1 and 5" << endl;

        }
    }
    while (choice != '5');


}

