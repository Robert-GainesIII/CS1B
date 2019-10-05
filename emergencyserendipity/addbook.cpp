#include "serendipity.h"

void addBook(string bookTitle[], string isbn[], string author[], string publisher[], string dateAdded[], int qtyOnHand[], double wholesale[], 
double retail[], int &bookCount)
{
	char choice = ' ';
	if (bookCount == DBSIZE)
	{
		cout << "ERROR Cannot add book the database is full ERROR" << endl;
		system("pause");
		invMenu(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, bookCount);
	}
	else if(bookCount < DBSIZE)
	{
		string tempBookTitle = "Empty";
		string tempISBN = "Empty";
		string tempAuthor = "Empty";
		string tempPublisher = "Empty";
		string tempDateAdded = "Empty";
		int tempQtyOnHand = 0;
		double tempWholesale = 0.00;
		double tempRetail = 0.00;
		do
		{
			char ch = ' ';
			if (bookCount == 20)
			{
				cout << "Books Saved Database Now Full" << endl;
				system("pause");
				invMenu(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, bookCount);
			}
			system("cls");
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "~" << right << setw(60) << "Serendipity Booksellers" << setw(33) << "~" << endl;
			cout << "~                                  Add Book                                                  ~" << endl;
			cout << "~ Database Size: " << DBSIZE << "                                            	Current Book Count: "<< bookCount << "       ~" << endl; 
			cout << "~                                                  >>>>> Temporary Data:                     ~" << endl;
			cout << "~ 1. Enter Book Title                              >>>>> " << left << setw(35) << tempBookTitle.substr(0,35) << " " << "~" << endl;
			cout << "~ 2. Enter ISBN                                    >>>>> " << left << setw(35) << tempISBN << " ~" << endl;
			cout << "~ 3. Enter Author                                  >>>>> " << left << setw(35) << tempAuthor << " ~" << endl;
			cout << "~ 4. Enter Publisher                               >>>>> " << left << setw(35) << tempPublisher << " ~" << endl;
			cout << "~ 5. Enter Date Added                              >>>>> " << left << setw(35) << tempDateAdded << " ~" << endl;
			cout << "~ 6. Enter Quantity On Hand                        >>>>> " << left << setw(35) << tempQtyOnHand << " ~" << endl;
			cout << "~ 7. Enter Wholesale Cost                          >>>>> " << left << setw(35) << tempWholesale << " ~" << endl;
			cout << "~ 8. Enter Retail Price                            >>>>> " << left << setw(35) << tempRetail << " ~" << endl;
			cout << "~ 9. Save Book to Database                                                                   ~" << endl;
			cout << "~ 0. Return to menu                                                                          ~" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Enter your choice: ";
			cin >> choice; cin.get(ch);
			switch (choice)
			{
				case '1':
				getline(cin, tempBookTitle);
					break;
				case '2':
				getline(cin, tempISBN);
					break;
				case '3':
				getline(cin, tempAuthor);
					break;
				case '4':
				getline(cin, tempPublisher);
					break;
				case '5':
				getline(cin, tempDateAdded);
					break;
				case '6':
				cin >> tempQtyOnHand; cin.get(ch);
					break;
				case '7':
				cin >> tempWholesale; cin.get(ch);
					break;
				case '8':
				cin >> tempRetail; cin.get(ch);
					break;
				case '9':
				bookTitle[bookCount] = tempBookTitle;
				isbn[bookCount] = tempISBN;
				author[bookCount] = tempAuthor;
				publisher[bookCount] = tempPublisher;
				dateAdded[bookCount] = tempDateAdded;
				qtyOnHand[bookCount] = tempQtyOnHand;
				wholesale[bookCount] = tempWholesale;
				retail[bookCount] = tempRetail;
				bookCount++;
					break;
				case '0':
				system("pause");
				invMenu(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, bookCount);
					break;
				default:
				cout << "Please enter a number in the range of 0 - 9" << endl;
				system("pause");
			}
			
		}while (choice !=0);
	}
}