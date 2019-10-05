#include "serendipity.h"
//displays a main menu that holds all the remaining functions in the program
void mainMenu(string bookTitle[], string isbn[], string author[], string publisher[], string dateAdded[], int qtyOnHand[], double wholesale[], double retail[], int &(bookCount))
{
    char choice = ' ';
	char ch = ' ';
    do
    {

        system("cls");
		cout << "----------------------------------" << endl;
        cout << "-      Serendipity Booksellers   -" << endl;
        cout << "-                 Menu           -" << endl << endl;
        cout << "- <1> Cashier Module             -" << endl;
        cout << "- <2> Inventory Database Module  -" << endl;
        cout << "- <3> Report Module              -" << endl;
        cout << "- <4> Exit                       -" << endl;
		cout << "----------------------------------" << endl;
        cout << " Enter your choice: " << endl;
        cin >> choice;
		system("cls");
        switch(choice)
        {
            case '1':
                cashier();
				do{
					cout << "Would you like to make another transaction? (Y/N)" << endl;
					cin >> ch;
					if(ch == 'Y' || ch == 'y')
					{
						system("pause");
						cashier();
					}
					else if (ch == 'N' || ch == 'n')
					{
						break;
					}
				}while(ch != 'Y' || ch != 'y' || ch == 'N' || ch == 'n');
                break;
            case '2':
                invMenu(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, bookCount);
                break;
            case '3':
                reports();
                break;
            case '4':
				cout << "Thank you for using Serendipity" << endl << endl;
				exit(1);
				system("pause");
                break;
            default:
                cout << "Please enter a range between 1-4" << endl;
				system("pause");


        }
	
    }
    while (choice != '4');

}
