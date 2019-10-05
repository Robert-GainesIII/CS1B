//Name: invmenu.cpp
//Purpose: Menu for inv where books can be added, deleted and edited
//Arguements passed: cols and rows of cmd window


#include "serendipity.h" 
#include "invmenu.h"
time_t g = time(NULL);

void inventory(orderedLinkedList<bookType> & books) {

	char choice ='5';
	do{
		system("cls");
		cout << setfill(' ');
		cout << setw(100) << right << "Serendipity BookStore." << endl;
		cout << setw(100) << right <<  "Inventory Database" << endl;
		
		cout << setw(100) << setfill('=') << "=" << endl;
		cout << "1. Look up a book" << endl;
		cout << "2. Add a Book" << endl;
		cout << "3. Edit a Book's Record" << endl;
		cout << "4. Delete a Book" << endl;
		cout << "5. Book Listing" << endl;
		cout << "6. Return to Main Menu" << endl << endl;
		cout << "Enter Your Choice: "; 
		cin >> choice;
		system("cls");
		string search;
		bookType currentBook;
		switch(choice){

			case '1':
				if(bookType::getBookCount() == 0){
					cout << "NO BOOKS IN DATABASE" << endl;
					system("pause");
				}
				else{
		
					currentBook = lookUp(books);
					bookType emptyBook;
					if(currentBook == emptyBook){
							cout << "BOOK NOT FOUND!" << endl;
							system("pause");
					}
				}
			break;

			case '2':
				add(books);
	
			break;

			case '3': 
				if(bookType::getBookCount()  == 0){
						cout << "NO BOOKS IN DATABASE" << endl;
						system("pause");
				}
				else{
					edit(books);
				}
			break;
			
			case '4':
				deleteBook(books);
		
			break;
			
			case '5':
				 //bookListing(books);
			break; 

			case '6':
			break; 
			
			default:
				cout << "Error!Error! Please Enter a choice (1-4)." << endl;
				system("pause");
		}
	}while(choice != '6');

}

void add(orderedLinkedList<bookType> & books){
	string tempName = "EMPTY";
	string tempAuthor = "EMPTY";
	string tempISBN = "EMPTY";
	string tempDate = "EMPTY";
	string tempPublisher = "EMPTY";
	int tempQty = 0;
	double tempWholesale = 0;
	double tempRetail= 0;
	char choice;
	char ch;

	do{
		//choice = ' ';
		system("cls");
		// if(bookType::getBookCount()  == 125){
			// cout << "DATABASE IS FULL..." << endl << "Returning User to Inventory Menu" << endl;
			// choice ='0';
			// system("pause");
		// }
		//else{
			int index = bookType::getBookCount();
			cout << "************************************************************************************************" << endl;
			cout << "*                                        SERENDIPITY BOOKSELLERS                               *" << endl;
			cout << "*                                               ADD BOOK                                       *" << endl;
			cout << "*                                                                                              *" << endl;
			cout << ctime(&g);
			cout << "*                                                     DATABASE SIZE:20  CURRENT BOOK COUNT: " << bookType::getBookCount()  << endl;
			cout << "*                                                                                           " << endl;
			cout << "*                                                                      --PENDING VALUES" << endl;
			cout << "*<1> Enter Book Title            > --" << tempName  <<  endl;
			cout << "*<2> Enter ISBN                  > --" << tempISBN  << endl;
			cout << "*<3> Enter Author                > --" << tempAuthor  << endl;
			cout << "*<4> Enter Publisher             > --" << tempPublisher  << endl;
			cout << "*<5> Enter Date Added (mm/dd/yy) > --" << tempDate << endl;
			cout << "*<6> Enter Quantity On Hand      > --" << tempQty  << endl;
			cout << "*<7> Enter Wholesale Cost        > --" << tempWholesale << endl;
			cout << "*<8> Enter Retail Price          > --" << tempRetail  << endl;
			cout << "*<9> Save Book To Database" << endl;
			cout << "*<0> Return To Inventory Menu" << endl;
			cout << "*                                                                                              *" << endl;
			cout << "*                                                                                              *" << endl;
			cout << "************************************************************************************************" << endl;
			cout << "         Choice<0-9>:  ";
			
			cin >>choice; 
			cin.ignore(20, '\n');
			cin.clear();
			
				switch(choice){
					case '0': 			
					break;
					
					case '1':
					getline(cin, tempName);
					break;
					
					case '2': 
					getline(cin, tempISBN);
					break;
					
					case '3': 
					getline(cin,tempAuthor);
					break;
					
					case '4': 
					getline(cin, tempPublisher);
					break;
					
					case '5': 
					getline(cin,tempDate);
					break;
					
					case '6': 
					
					cin >> tempQty;
					while(!cin){
						cout << "must enter an number value for this variable!" << endl;
						cin.ignore();
						cin.clear();
						cin >> tempQty;
					}
					break;
					
					case '7': 
			
					cin >> tempWholesale; 
					while(!cin){
						cout << "must enter an number value for this variable!" << endl;
						cin.ignore();
						cin.clear();
						cin >> tempWholesale;
					}
					
					break;
					
					case '8': 
			
					cin >> tempRetail;
					while(!cin){
						cout << "must enter an number value for this variable!" << endl;
						cin.ignore();
						cin.clear();
						cin >> tempRetail;
					}
					break;
					
					case '9': 
					//if(bookType::getBookCount()  <= 125){
					bookType book(tempName, tempISBN, tempAuthor, tempPublisher, tempDate, tempQty, tempWholesale, tempRetail, bookType::getBookCount());
					books.insert(book);
					bookType::incBookCount();
					bookType::setDBSIZE(bookType::getBookCount());
					// books[index].setBookTitle(tempName);
					// books[index].setISBN(tempISBN);
					// books[index].setAuthor(tempAuthor);
					// books[index].setPublisher(tempPublisher);
					// books[index].setDateAdded(tempDate);
					// books[index].setQtyOnHand(tempQty);
					// books[index].setWholesale(tempWholesale);
					// books[index].setRetail(tempRetail);
							ofstream out; 
						out.open("database.txt");
						linkedListIterator<bookType> it;
						int index = 0;
						for(it = books.begin(); it != books.end(); ++it){
							bookType temp = *it;
							if(index == bookType::getBookCount()-1){
							out << temp.getBookTitle() << endl;
							out <<  temp.getISBN() << endl;
							out << temp.getAuthor() << endl;
							out <<  temp.getPublisher() << endl;
							out <<  temp.getDateAdded() << endl;
							out << temp.getQtyOnHand() << endl;
							out <<  temp.getWholesale() << endl;
							out << temp.getRetail();
							break;
							}
							else{
							out << temp.getBookTitle() << endl;
							out <<  temp.getISBN() << endl;
							out << temp.getAuthor() << endl;
							out <<  temp.getPublisher() << endl;
							out <<  temp.getDateAdded() << endl;
							out << temp.getQtyOnHand() << endl;
							out <<  temp.getWholesale() << endl;
							out << temp.getRetail() << endl;
							}
							index++;
						}
						cout << "SAVED EDITS TO DATABASE.TXT" << endl;
						system("pause");
						out.close();
					
					//}
					break;
					
					default: 
					cout << "Enter Valid Selection <0-9>!!!!!" << endl;
					system("pause");
			}
		//}
	}while(choice != '0');
}

void edit(orderedLinkedList<bookType> & books){
	
		bookType emptyBook;
		bookType originalBook = lookUp(books);
		bookType editedBook;
		editedBook = originalBook;
		if(!(originalBook == emptyBook)){
			//cout << originalBook;
			cout<<"Is this the record you would like to edit?(y/n):";
			char c;
			cin >> c;
			if(c == 'y'){
				editRecord(editedBook);
				books.editNode(originalBook, editedBook);
				ofstream out; 
				out.open("database.txt");
				linkedListIterator<bookType> it;
				int index = 0;
				for(it = books.begin(); it != books.end(); ++it){
					bookType temp = *it;
					if(index == bookType::getBookCount()-1){
					out << temp.getBookTitle() << endl;
					out <<  temp.getISBN() << endl;
					out << temp.getAuthor() << endl;
					out <<  temp.getPublisher() << endl;
					out <<  temp.getDateAdded() << endl;
					out << temp.getQtyOnHand() << endl;
					out <<  temp.getWholesale() << endl;
					out << temp.getRetail();
					break;
					}
					else{
					out << temp.getBookTitle() << endl;
					out <<  temp.getISBN() << endl;
					out << temp.getAuthor() << endl;
					out <<  temp.getPublisher() << endl;
					out <<  temp.getDateAdded() << endl;
					out << temp.getQtyOnHand() << endl;
					out <<  temp.getWholesale() << endl;
					out << temp.getRetail() << endl;
					}
					index++;
				}
				cout << "SAVED EDITS TO DATABASE.TXT" << endl;
				system("pause");
				out.close();
			}
		}
}

void deleteBook(orderedLinkedList<bookType> & books){

		bookType emptyBook;
		bookType book = lookUp(books);
		
			if(!(book == emptyBook)){
			//cout << book;
			cout<<"Is this the record you would like to delete?(y/n):";
			char c;
			cin >> c;
			if(c == 'y'){
				
				books.deleteNode(book);
				bookType::decBookCount();
	
				ofstream out; 
				out.open("database.txt");
				linkedListIterator<bookType> it;
				int index = 0;
				for(it = books.begin(); it != books.end(); ++it){
					bookType temp = *it;
					if(index == bookType::getBookCount()-1){
					out << temp.getBookTitle() << endl;
					out <<  temp.getISBN() << endl;
					out << temp.getAuthor() << endl;
					out <<  temp.getPublisher() << endl;
					out <<  temp.getDateAdded() << endl;
					out << temp.getQtyOnHand() << endl;
					out <<  temp.getWholesale() << endl;
					out << temp.getRetail();
					break;
					}
					else{
					out << temp.getBookTitle() << endl;
					out <<  temp.getISBN() << endl;
					out << temp.getAuthor() << endl;
					out <<  temp.getPublisher() << endl;
					out <<  temp.getDateAdded() << endl;
					out << temp.getQtyOnHand() << endl;
					out <<  temp.getWholesale() << endl;
					out << temp.getRetail() << endl;
					}
					index++;
				}
				cout << "SAVED EDITS TO DATABASE.TXT" << endl;
				system("pause");
				out.close();
			}
		}

}

void editRecord(bookType & book){
	string tempName = "EMPTY";
	string tempAuthor = "EMPTY";
	string tempISBN = "EMPTY";
	string tempDate = "EMPTY";
	string tempPublisher = "EMPTY";
	int tempQty = 0;
	double tempWholesale = 0;
	double tempRetail= 0;
	char choice;
	string ch;
	

	do{
		//choice = ' ';
		system("cls");
		cout << "************************************************************************************************" << endl;
		cout << "*                                        SERENDIPITY BOOKSELLERS                               *" << endl;
		cout << "*                                               EDIT RECORD                                    *" << endl;
		cout << ctime(&g);
		cout << "*                                                                                              *" << endl;
		cout << "*                           `	                                                                 " << endl;
		cout << "*<1> Enter Book Title            > --" << book.getBookTitle() << "                                        " << endl;
		cout << "*<2> Enter ISBN                  > --" << book.getISBN()  << "                                            " << endl;
		cout << "*<3> Enter Author                > --" << book.getAuthor()  << "                                          " << endl;
		cout << "*<4> Enter Publisher             > --" << book.getPublisher()  << "                                       " << endl;
		cout << "*<5> Enter Date Added (mm/dd/yy) > --" << book.getDateAdded() << "                                       " << endl;
		cout << "*<6> Enter Quantity On Hand      > --" << book.getQtyOnHand()  << "                                       " << endl;
		cout << "*<7> Enter Wholesale Cost        > --" << book.getWholesale()  << "                                       " << endl;
		cout << "*<8> Enter Retail Price          > --" << book.getRetail()  << "                                          " << endl;
		cout << "*<0> Return To Inventory Menu                                                                   " << endl;
		cout << "*                                                                                               " << endl;
		cout << "************************************************************************************************" << endl;
		cout << "         Choice<0-8>:  ";
		
		cin >>choice; 
		cin.ignore(20, '\n');
		cin.clear();
		
		cout << ">>";
		switch(choice){
			case '0': 			
			break;
			case '1': 
			getline(cin, tempName);
			book.setBookTitle(tempName);
			break;
			case '2': 
			getline(cin, tempISBN);
			book.setISBN(tempISBN);
			break;
			case '3': 
			getline(cin,tempAuthor);
			book.setAuthor(tempAuthor);
			break;
			case '4': 
			getline(cin, tempPublisher);
			book.setPublisher(tempPublisher);
			break;
			case '5': 
			getline(cin,tempDate);
			book.setDateAdded(tempDate);
			break;
			case '6': 

			cin >> tempQty;
			while(!cin){
						cout << "must enter an number value for this variable!" << endl;
						cin.clear();
						cin >> tempQty;
					}
			book.setQtyOnHand(tempQty);
			
			break;
			case '7': 
	
			cin >> tempWholesale;
			while(!cin){
						cout << "must enter an number value for this variable!" << endl;
						cin.clear();
						cin >> tempWholesale;
					}
			book.setWholesale(tempWholesale);
			break;
			case '8': 
	
			cin >> tempRetail;
			while(!cin){
						cout << "must enter an number value for this variable!" << endl;
						cin.clear();
						cin >> tempRetail;
					}
			book.setRetail(tempRetail);
			break;
			
			default: 
			cout << "Enter Valid Selection <0-9>!!!!!" << endl;
			system("pause");
		}
	}while(choice != '0');
	
}









