#include "serendipity.h"


void cashier(){
	
string date ="";
int quantity = 0;
string isbn = "";
char title[50];
double price = 0;
double subTotal = 0;
double tax = 0;
double total;

cout << "Enter the date: ";
cin >> date;
cout << "Enter the quantity purchased: ";
cin >> quantity;
cout << "Enter the ISBN: ";
cin >> isbn;
cout << "Enter the title: ";
cin.ignore(100,'\n');
cin.getline(title,50);
cout << "Enter the price of the book(s): ";
cin >> price;

system("cls");
cout << "-----------------------------------------------------------------------------------------------------" << endl;
cout << "-                          Serendipity Booksellers                                                  -" << endl;
cout << "- Date: " << date << "                                                                              -" << endl;
subTotal = price * quantity;
cout << "- Qty: " << quantity << "   "  <<"ISBN: " << isbn << "   "   <<"Title: " << title << "   " << "Price: " << price << "   " << "Total: " << subTotal << endl;
cout << "-----------------------------------------------------------------------------------------------------" << endl << endl << endl;
cout << fixed << showpoint << setprecision(2);
cout << setw(43) << "Subtotal: " << setw(46) << subTotal << "$" << endl;
tax = subTotal * 0.06; 
cout << setw(38) << "Tax: " << setw(50) << tax << "$" <<endl;
total = subTotal + tax;
cout << setw(40) << "Total: " << setw(49) << total << "$"<<  endl << endl;
cout << "Thank you for shopping at Serendipity!" << endl;

system("pause");


}

