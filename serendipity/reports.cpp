//Name: reports.cpp
//Purpose: Report Menu where data about costs and where books can be sorted
//Arguements passed: cols and rows of cmd window

#include "serendipity.h" 
#include "reports.h"
time_t f = time(NULL);

void reports(orderedLinkedList<bookType> & books){
	
	char choice ='7';
	do{
		system("cls");
		cout << setfill(' ');
		//cout << setw() << right << "Serendipity BookStore." << endl;
		//cout << setw() <<right <<  "Reports" << endl;
		
		//cout << setw(columns) << setfill('=') << "=" << endl;
		cout << "1. Inventory Listing" << endl;
		cout << "2. Inventory Wholesale Value" << endl;
		cout << "3. Inventory Retail Value" << endl;
		cout << "4. Listing by Quantity" << endl;
		cout << "5. Listing by Cost" << endl;
		cout << "6. Listing by Age" << endl;
		cout << "7. Return to Main Menu" << endl;
		cout << "Enter Your Choice: " << endl;
		cin >> choice;
		system("cls");
		
		//sanitize input and flush cin buffer
		cin.clear();
		cin.ignore(100, '\n');
		switch(choice){

			case '1': 
				InventoryListing(books);
			break;
			
			case '2':
				wholesaleListing(books);
			break;

			case '3': 
				retailListing(books);
			break;
			
			case '4':
				listByQuantity(books);
			break;
			
			case '5':
				listByCost(books);
			break; 
			
			case '6':
				listByAge(books);
			break;
			
			case '7':
			//return main menu
			break;
			
			default:
				cout << "Error!Error! Please Enter a choice (1-4)." << endl;
				system("pause");
		}
	}while(choice != '7');
	
}




void InventoryListing(orderedLinkedList<bookType> & books){
		int count = 1;
		cout << "************************************************************************************************************************************" << endl;
		cout << "*                                                        SERENDIPITY BOOKSELLERS                               		           *" << endl;
		cout << "*                                                            REPORT LISTING                                                        *" << endl;
		cout << "*" << ctime(&f) << " Page Number: " << count << "DATABASE SIZE: " << bookType::getDBSIZE() << " CURRENT BOOK COUNT: " << bookType::getBookCount() << endl;
		cout << "************************************************************************************************************************************" << endl;
		cout << "*" << setw(40) << left << "TITLE" << 
					   setw(20) << "ISBN" << 
					   setw(20) << "AUTHOR" <<
					   setw(20) << "PUBLISHER" << 
					   setw(20) << "DATE ADDED" << 
					   setw(20) << "QTY O/H" <<
					   setw(20) << "WHOLESALE COST" << 
					   setw(20) << "RETAIL PRICE" << endl;
					   
		cout << "*" << setw(40) << setfill('-') << '-' << 
					   setw(20) << '-' <<
					   setw(20) << '-' << 
					   setw(20) << '-' <<
					   setw(20) << '-' << 
					   setw(20) << '-' << 
					   setw(20) << '-' << 
					   setw(20) << '-' << endl; 
		// for(int i = 0; i < bookType::getBookCount(); i++){
		orderedLinkedList<bookType> list;
		linkedListIterator<bookType> iterator;
		for(iterator = books.begin(); iterator != books.end(); ++iterator){
			bookType temp = *iterator;
			temp.setSortCode(0);
			list.insert(temp);
		}
		int index = 1;
		for(iterator = books.begin(); iterator != books.end(); ++iterator){
		
		bookType temp = *iterator;
			cout << setfill(' ');
		 
			
			cout << "*" << setw(40) << left << temp.getBookTitle().substr(0,29) << 
					   setw(20) << temp.getISBN() << 
					   setw(20) << temp.getAuthor().substr(0,14) <<
					   setw(20) << temp.getPublisher().substr(0,14) << 
					   setw(20) << temp.getDateAdded() << 
					   setw(20) << temp.getQtyOnHand() <<
					   "$ "<< setw(19) << temp.getWholesale() << 
					   "$ "<< setw(19) << temp.getRetail() << endl << endl;
			
			
			if(index%26 == 0){
				count++;
				system("pause");
				system("cls");
				cout << "************************************************************************************************************************************" << endl;
				cout << "*                                                        SERENDIPITY BOOKSELLERS                               		           *" << endl;
				cout << "*                                                            REPORT LISTING                                                        *" << endl;
				cout << "*" << ctime(&f) << " Page Number: " << count << "DATABASE SIZE: " << bookType::getDBSIZE() << " CURRENT BOOK COUNT: " << bookType::getBookCount() << endl;
				cout << "************************************************************************************************************************************" << endl;
				cout << "*" << setw(40) << left << "TITLE" << 
					   setw(20) << "ISBN" << 
					   setw(20) << "AUTHOR" <<
					   setw(20) << "PUBLISHER" << 
					   setw(20) << "DATE ADDED" << 
					   setw(20) << "QTY O/H" <<
					   setw(20) << "WHOLESALE COST" << 
					   setw(20) << "RETAIL PRICE" << endl;
					   
				cout << "*" << setw(40) << setfill('-') << '-' << 
					   setw(20) << '-' <<
					   setw(20) << '-' << 
					   setw(20) << '-' <<
					   setw(20) << '-' << 
					   setw(20) << '-' << 
					   setw(20) << '-' << 
					   setw(20) << '-' << endl; 
			}
			index ++;
		}
		system("pause");
}


void wholesaleListing(orderedLinkedList<bookType> & books){
	
		int count = 0;
		cout << "************************************************************************************************************************************" << endl;
		cout << "*                                                        SERENDIPITY BOOKSELLERS                               		           *" << endl;
		cout << "*                                                           WHOLESALE LISTING                                                      *" << endl;
		cout << "*" << ctime(&f) << " Page Number: " << count << "DATABASE SIZE: " << bookType::getDBSIZE() << " CURRENT BOOK COUNT: " << bookType::getBookCount()<< endl;
		cout << "************************************************************************************************************************************" << endl;
		
	    cout << "*" << setw(80) << left << "TITLE" << 
					   setw(20) << "ISBN" << 
					   setw(20) << "QTY O/H" <<
					   setw(20) << "WHOLESALE COST" << endl;
					   
		cout << "*" << setw(80) << setfill('-') << '-' << 
					   setw(20) << '-' <<
					   setw(20) << '-' << 
					   setw(20) << '-' << endl;
					   
		double total = 0;

		// for(int i = 0; i < bookType::getBookCount(); i++){
		orderedLinkedList<bookType> list;
		linkedListIterator<bookType> iterator;
		for(iterator = books.begin(); iterator != books.end(); ++iterator){
			bookType temp = *iterator;
			temp.setSortCode(0);
			list.insert(temp);
		}
		int index = 1;
		for(iterator = list.begin(); iterator != list.end(); ++iterator){
		bookType temp = *iterator;
		cout << setfill(' ');
			
			cout << "*" << setw(80) << left << temp.getBookTitle()<< 
					   setw(20) << temp.getISBN() << 
					   setw(20) << temp.getQtyOnHand() <<
					   "$ " << setw(19) << temp.getWholesale() << endl << endl;
			
			total += temp.getWholesale() * temp.getQtyOnHand();
			
			if(index%26 == 0){
				count++;
				system("pause");
				system("cls");
				cout << "************************************************************************************************************************************" << endl;
				cout << "*                                                        SERENDIPITY BOOKSELLERS                               		           *" << endl;
				cout << "*                                                            WHOLESALE LISTING                                                     *" << endl;
				cout << "*" << ctime(&f) << " Page Number: " << count << "DATABASE SIZE: " << bookType::getDBSIZE() << " CURRENT BOOK COUNT: " << bookType::getBookCount()<< endl;
				cout << "************************************************************************************************************************************" << endl;
				cout << "*" << setw(80) << left << "TITLE" << 
							   setw(20) << "ISBN" << 
							   setw(20) << "QTY O/H" <<
							   setw(20) << "WHOLESALE COST" << endl;
							   
				cout << "*" << setw(80) << setfill('-') << '-' << 
							   setw(20) << '-' <<
							   setw(20) << '-' << 
							   setw(20) << '-' << endl;
							   
			}
			index ++;
		}
		cout << fixed << setprecision(2) << "*TOTAL WHOLESALE VALUE: $" << total << endl << endl;
		system("pause");
	
}


void retailListing(orderedLinkedList<bookType> & books){
		int count = 0;
		cout << "************************************************************************************************************************************" << endl;
		cout << "*                                                        SERENDIPITY BOOKSELLERS                               		           *" << endl;
		cout << "*                                                           WHOLESALE LISTING                                                      *" << endl;
		cout << "*" << ctime(&f) << " Page Number: " << count << "DATABASE SIZE: " << bookType::getDBSIZE() << " CURRENT BOOK COUNT: " << bookType::getBookCount()<< endl;
		cout << "************************************************************************************************************************************" << endl;
		
	    cout << "*" << setw(80) << left << "TITLE" << 
					   setw(20) << "ISBN" << 
					   setw(20) << "QTY O/H" <<
					   setw(20) << "RETAIL COST" << endl;
					   
		cout << "*" << setw(80) << setfill('-') << '-' << 
					   setw(20) << '-' <<
					   setw(20) << '-' << 
					   setw(20) << '-' << endl;
					   
		double total = 0;

		// for(int i = 0; i < bookType::getBookCount(); i++){
		orderedLinkedList<bookType> list;
		linkedListIterator<bookType> iterator;
		for(iterator = books.begin(); iterator != books.end(); ++iterator){
			bookType temp = *iterator;
			temp.setSortCode(0);
			list.insert(temp);
		}
		int index = 1;
		for(iterator = list.begin(); iterator != list.end(); ++iterator){
		bookType temp = *iterator;
		cout << setfill(' ');
			
			cout << "*" << setw(80) << left << temp.getBookTitle()<< 
					   setw(20) << temp.getISBN() << 
					   setw(20) << temp.getQtyOnHand() <<
					   "$ " << setw(19) << temp.getRetail() << endl << endl;
			
			total += temp.getRetail() * temp.getQtyOnHand();
			
			if(index%26 == 0){
				count++;
				system("pause");
				system("cls");
				cout << "************************************************************************************************************************************" << endl;
				cout << "*                                                        SERENDIPITY BOOKSELLERS                               		           *" << endl;
				cout << "*                                                            WHOLESALE LISTING                                                     *" << endl;
				cout << "*" << ctime(&f) << " Page Number: " << count << "DATABASE SIZE: " << bookType::getDBSIZE() << " CURRENT BOOK COUNT: " << bookType::getBookCount()<< endl;
				cout << "************************************************************************************************************************************" << endl;
				cout << "*" << setw(80) << left << "TITLE" << 
							   setw(20) << "ISBN" << 
							   setw(20) << "QTY O/H" <<
							   setw(20) << "RETAIL COST" << endl;
							   
				cout << "*" << setw(80) << setfill('-') << '-' << 
							   setw(20) << '-' <<
							   setw(20) << '-' << 
							   setw(20) << '-' << endl;
							   
			}
			index ++;
		}
		cout << fixed << setprecision(2) << "*TOTAL RETAIL VALUE: $" << total << endl << endl;
		system("pause");
}


void listByQuantity(orderedLinkedList<bookType> & books){
	int count = 0;
		cout << "************************************************************************************************************************************" << endl;
		cout << "*                                                        SERENDIPITY BOOKSELLERS                               		           *" << endl;
		cout << "*                                                           WHOLESALE LISTING                                                      *" << endl;
		cout << "*" << ctime(&f) << " Page Number: " << count << "DATABASE SIZE: " << bookType::getDBSIZE() << " CURRENT BOOK COUNT: " << bookType::getBookCount()<< endl;
		cout << "************************************************************************************************************************************" << endl;
		
	    cout << "*" << setw(80) << left << "TITLE" << 
					   setw(20) << "ISBN" << 
					   setw(20) << "QTY O/H" << endl;
					   
		cout << "*" << setw(80) << setfill('-') << '-' << 
					   setw(20) << '-' <<
					   setw(20) << '-' <<  endl;
					   
		double total = 0;

		// for(int i = 0; i < bookType::getBookCount(); i
		bookType bookArry[bookType::getBookCount()];
		bookType sortedArry[bookType::getBookCount()];
		orderedLinkedList<bookType> list;
		linkedListIterator<bookType> iterator;
		linkedListIterator<bookType> innerIterator;
		int innerIndex=0;
		int outerIndex =0;
		
		for(iterator = books.begin(); iterator != books.end(); ++iterator){
			
			bookType newbook = *iterator;
			bookArry[outerIndex] = newbook;
			outerIndex++;
			
		}
			int lowest;
			int newLowest;
			for(int i = 0; i < bookType::getBookCount()-1; i++){
				
				for(int j = 0; j < bookType::getBookCount()-1; j++){
					if(bookArry[j].getQtyOnHand() > bookArry[j+1].getQtyOnHand()){
				
						bookType temp = bookArry[j+1];
						bookArry[j+1] = bookArry[j];
						bookArry[j] = temp;
					}
				}
				list.insert(bookArry[(bookType::getBookCount()-1)-i]);
			}
		
	
		int index = 1;
		for(iterator = list.begin(); iterator != list.end(); ++iterator){
		bookType temp = *iterator;
		cout << setfill(' ');
			
			cout << "*" << setw(80) << left << temp.getBookTitle()<< 
					   setw(20) << temp.getISBN() << 
					   setw(20) << temp.getQtyOnHand() << endl << endl;
			
			if(index%26 == 0){
				count++;
				system("pause");
				system("cls");
				cout << "************************************************************************************************************************************" << endl;
				cout << "*                                                        SERENDIPITY BOOKSELLERS                               		           *" << endl;
				cout << "*                                                            WHOLESALE LISTING                                                     *" << endl;
				cout << "*" << ctime(&f) << " Page Number: " << count << "DATABASE SIZE: " << bookType::getDBSIZE() << " CURRENT BOOK COUNT: " << bookType::getBookCount()<< endl;
				cout << "************************************************************************************************************************************" << endl;
				cout << "*" << setw(80) << left << "TITLE" << 
							   setw(20) << "ISBN" << 
							   setw(20) << "QTY O/H" << endl;
							   
				cout << "*" << setw(80) << setfill('-') << '-' << 
							   setw(20) << '-' <<
							   setw(20) << '-' << endl;
							   
			}
			index ++;
		}
		system("pause");
	
}


void listByCost(orderedLinkedList<bookType> & books){
	int count = 0;
		cout << "************************************************************************************************************************************" << endl;
		cout << "*                                                        SERENDIPITY BOOKSELLERS                               		           *" << endl;
		cout << "*                                                           WHOLESALE LISTING                                                      *" << endl;
		cout << "*" << ctime(&f) << " Page Number: " << count << "DATABASE SIZE: " << bookType::getDBSIZE() << " CURRENT BOOK COUNT: " << bookType::getBookCount()<< endl;
		cout << "************************************************************************************************************************************" << endl;
		
	    cout << "*" << setw(80) << left << "TITLE" << 
					   setw(20) << "ISBN" << 
					   setw(20) << "WHOLESALE PRICE" << endl;
					   
		cout << "*" << setw(80) << setfill('-') << '-' << 
					   setw(20) << '-' <<
					   setw(20) << '-' <<  endl;
					   
		double total = 0;

		// for(int i = 0; i < bookType::getBookCount(); i
		bookType bookArry[bookType::getBookCount()];
		bookType sortedArry[bookType::getBookCount()];
		orderedLinkedList<bookType> list;
		linkedListIterator<bookType> iterator;
		linkedListIterator<bookType> innerIterator;
		int innerIndex=0;
		int outerIndex =0;
		
		for(iterator = books.begin(); iterator != books.end(); ++iterator){
			
			bookType newbook = *iterator;
			bookArry[outerIndex] = newbook;
			outerIndex++;
			
		}
			int lowest;
			int newLowest;
			for(int i = 0; i < bookType::getBookCount()-1; i++){
				
				for(int j = 0; j < bookType::getBookCount()-1; j++){
					if(bookArry[j].getWholesale() > bookArry[j+1].getWholesale()){
				
						bookType temp = bookArry[j+1];
						bookArry[j+1] = bookArry[j];
						bookArry[j] = temp;
					}
				}
				list.insert(bookArry[(bookType::getBookCount()-1)-i]);
			}
		
	
		int index = 1;
		for(iterator = list.begin(); iterator != list.end(); ++iterator){
		bookType temp = *iterator;
		cout << setfill(' ');
			
			cout << "*" << setw(80) << left << temp.getBookTitle()<< 
					   setw(20) << temp.getISBN() << 
					   "$ " << setw(19) << temp.getWholesale() << endl << endl;
			
			if(index%26 == 0){
				count++;
				system("pause");
				system("cls");
				cout << "************************************************************************************************************************************" << endl;
				cout << "*                                                        SERENDIPITY BOOKSELLERS                               		           *" << endl;
				cout << "*                                                            WHOLESALE LISTING                                                     *" << endl;
				cout << "*" << ctime(&f) << " Page Number: " << count << "DATABASE SIZE: " << bookType::getDBSIZE() << " CURRENT BOOK COUNT: " << bookType::getBookCount()<< endl;
				cout << "************************************************************************************************************************************" << endl;
				cout << "*" << setw(80) << left << "TITLE" << 
							   setw(20) << "ISBN" << 
							   setw(20) << "WHOLESALE PRICE" << endl;
							   
				cout << "*" << setw(80) << setfill('-') << '-' << 
							   setw(20) << '-' <<
							   setw(20) << '-' << endl;
							   
			}
			index ++;
		}
		system("pause");
}


void listByAge(orderedLinkedList<bookType> & books){
	
	int count = 0;
		cout << "************************************************************************************************************************************" << endl;
		cout << "*                                                        SERENDIPITY BOOKSELLERS                               		           *" << endl;
		cout << "*                                                           WHOLESALE LISTING                                                      *" << endl;
		cout << "*" << ctime(&f) << " Page Number: " << count << "DATABASE SIZE: " << bookType::getDBSIZE() << " CURRENT BOOK COUNT: " << bookType::getBookCount()<< endl;
		cout << "************************************************************************************************************************************" << endl;
		
	    cout << "*" << setw(80) << left << "TITLE" << 
					   setw(20) << "ISBN" << 
					   setw(20) << "QTY O/H" << 
					   setw(30) << "DATE ADDED" << endl;
					   
		cout << "*" << setw(80) << setfill('-') << '-' << 
					   setw(20) << '-' <<
					   setw(20) << '-' <<  
					   setw(30) << '-' << endl;
					   
		double total = 0;

		// for(int i = 0; i < bookType::getBookCount(); i
		bookType bookArry[bookType::getBookCount()];
		bookType sortedArry[bookType::getBookCount()];
		orderedLinkedList<bookType> list;
		linkedListIterator<bookType> iterator;
		linkedListIterator<bookType> innerIterator;
		int innerIndex=0;
		int outerIndex =0;
		
		for(iterator = books.begin(); iterator != books.end(); ++iterator){
			
			bookType newbook = *iterator;
			bookArry[outerIndex] = newbook;
			outerIndex++;
			
		}
			int lowest;
			int newLowest;
			for(int i = 0; i < bookType::getBookCount()-1; i++){
				
				for(int j = 0; j < bookType::getBookCount()-1; j++){
					
					if(bookArry[j].year > bookArry[j+1].year){
						bookType temp = bookArry[j+1];
						bookArry[j+1] = bookArry[j];
						bookArry[j] = temp;
					}
					if((bookArry[j].year == bookArry[j+1].year) && (bookArry[j].month > bookArry[j+1].month)){
							bookType temp = bookArry[j+1];
							bookArry[j+1] = bookArry[j];
							bookArry[j] = temp;
						
					}
					if((bookArry[j].year == bookArry[j+1].year) && (bookArry[j].month  == bookArry[j+1].month ) &&(bookArry[j].day > bookArry[j+1].day)){
							bookType temp = bookArry[j+1];
							bookArry[j+1] = bookArry[j];
							bookArry[j] = temp;
						
					}
						
				}
				list.insert(bookArry[(bookType::getBookCount()-1)-i]);
			}
		
	
		int index = 1;
		for(iterator = list.begin(); iterator != list.end(); ++iterator){
		bookType temp = *iterator;
		cout << setfill(' ');
			
			cout << "*" << setw(80) << left << temp.getBookTitle()<< 
					   setw(20) << temp.getISBN() << 
					   setw(20) << temp.getQtyOnHand() <<
					   setw(30) << temp.getDateAdded() << endl << endl;
			
			if(index%26 == 0){
				count++;
				system("pause");
				system("cls");
				cout << "************************************************************************************************************************************" << endl;
				cout << "*                                                        SERENDIPITY BOOKSELLERS                               		           *" << endl;
				cout << "*                                                            WHOLESALE LISTING                                                     *" << endl;
				cout << "*" << ctime(&f) << " Page Number: " << count << "DATABASE SIZE: " << bookType::getDBSIZE() << " CURRENT BOOK COUNT: " << bookType::getBookCount()<< endl;
				cout << "************************************************************************************************************************************" << endl;
				cout << "*" << setw(80) << left << "TITLE" << 
							   setw(20) << "ISBN" << 
							   setw(20) << "QTY O/H" <<
							   setw(30) << "DATE ADDED" << endl;
							   
							   
				cout << "*" << setw(80) << setfill('-') << '-' << 
							   setw(20) << '-' <<
							   setw(20) << '-' << 
							   setw(30) << '-' << endl;
							   
			}
			index ++;
		}
		system("pause");
}
