
#include "serendipity.h"

//displays a reports menu that has different options the user can select from 
void reports(){
char choice = ' ';
    do{
		system("cls");
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "~      Serendipity Booksellers       ~" << endl;
        cout << "~             Reports                ~" << endl;
		cout << "~                                    ~" << endl;
        cout << "~ <1> Inventory Listing              ~" << endl;
        cout << "~ <2> Inventory Wholesale Value      ~" << endl;
        cout << "~ <3> Inventory Retail Value         ~" << endl;
        cout << "~ <4> Listing by Quantity            ~" << endl;
        cout << "~ <5> Listing by Cost                ~" << endl;
        cout << "~ <6> Listing by Age                 ~" << endl;
        cout << "~ <7> Return to Main Menu            ~" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
		cout << endl;
        switch (choice)
        {
            case '1':
                repListing();
				system("pause");
                break;
            case '2':
                repWholesale();
				system("pause");
                break;
            case '3':
                repRetail();
				system("pause");
                break;
            case '4':
                repQty();
				system("pause");
                break;
            case '5':
                repCost();
				system("pause");
                break;
            case '6':
                repAge();
				system("pause");
                break;
            case '7':
                break;
            default:
                cout << "Please enter a range between 1 and 7" << endl;

        }
    }
    while (choice != '7');

}
