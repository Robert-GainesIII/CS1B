//Name: cashier.cpp
//Purpose: Print and calculate sale receipt
//Arguements passed: cols and rows of cmd window

#include "serendipity.h"


void cashier(orderedLinkedList<bookType> & books){
	int orderAmount[bookType::getDBSIZE()] = {0};
	bookType bookCopies[bookType::getDBSIZE()];
	int quantity = 0;
	float total = 0;
	float subtotal = 0;
	bool back = false;
	double tax = 0.06;
	char choice = 'Z';
	time_t t = time(NULL);
	string x;
	int index = 0;
	bookType currentBook;
	bookType emptyBook;
	bookType editedBook;
	do{

							
			currentBook = lookUp(books);
	

			if(!(currentBook == emptyBook)){
					index = currentBook.getIndex();
					bookCopies[index] = currentBook;
				
					//GET QUANTITY CHECKS FOR LOGIC ERRORS
					do{
						cout << "Enter the # of Books Desired: "; 
						cin >> quantity;
						cin.ignore(20, '\n');
						cin.clear();
						
						if(!cin){
						cout << quantity << " Character was entered as input!";
						system("pause");
						}
						if(quantity > currentBook.getQtyOnHand()){
						   cout<<"Sorry there are only " << currentBook.getQtyOnHand() << " In stock." << endl;
						   system("pause");
						}
					
						 
					}while(quantity < 0 || quantity > currentBook.getQtyOnHand());
				
				 //UPDATE PARELLEL ARRAY WITH NEW DATA
				 orderAmount[index] += quantity;
				 
				 
				}else{
						//IF BOOK WAS NOT FOUND 
						cout << "Book Not Found" << endl;
				}
				
			cout << "Would you Like to search for another purchase?" << endl;
			cin >> choice;
			cin.ignore(10,'\n');
			cin.clear();
			if(choice ==  'y' || choice == 'Y'){
					
			}
			else{
				 system("cls");
				 cout << "Serendipity Book Sellers" << endl << endl;
				 cout << ctime(&t);
				 cout << setw(10) << "Qty" << setw(20) << "ISBN" << setw(40) << "Title" << setw(20) << "Price" << setw(20) << "Total" << endl;
				 cout << setw(120) << setfill('_') << "_"<< endl;
				 cout << setfill(' ');
				 
					 //LOOP THROUGH PARELLEL ARRAY AND CALCULATE RECEIPT
					 for(int i = 0; i < bookType::getDBSIZE(); i++){
						 
						 if(orderAmount[i] > 0){
							 total = bookCopies[i].getRetail() * orderAmount[i];
							 cout << setw(10) << orderAmount[i] << setw(20) << bookCopies[i].getISBN() << setw(40) << bookCopies[i].getBookTitle().substr(0,39) << setw(20) << bookCopies[i].getRetail() << setw(20) << total << endl;
							 subtotal += total;
						 }
						 
					 }
				cout << endl << endl << endl;
				cout << setw(30) << "Subtotal" << setw(60) << subtotal << endl;
				cout << setw(30) << "Tax" << setw(60) << (subtotal*tax) << endl;
				cout << setw(30) << "Total" << setw(60) << subtotal + (subtotal * tax) << endl << endl;
				cout << "Confirm Purchase (y) or cancel purchase (n)??" << endl;
				cin >> choice; 
				cin.ignore(10,'\n');
				cin.clear();
				
				//CONFIRM PURCHASE OR EXIT PURCHASE
				if(choice ==  'y' || choice == 'Y'){
					for(int i = 0; i < bookType::getDBSIZE(); i++){
						if(orderAmount[i] > 0){
							int total = bookCopies[i].getQtyOnHand() - orderAmount[i];
							editedBook = bookCopies[i];
							editedBook.setQtyOnHand(total);
							books.editNode(bookCopies[i], editedBook);
						}
					}
					//prompt the user to process another receipt i.e dont exit this loop
					cout << "would you like to process another reciept?(y/n)";
					cin >> choice;
					cin.ignore(10,'\n');
					cin.clear();
					if(choice ==  'y' || choice == 'Y'){
						
					}
					else{
						back = true;
					}
				}else{
					back = true;
				}
				
			}
			//END OF CASHIER MODULE
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
			system("pause");
			index++;
	}while(!back);
	
	//CALCULATE RECIEPT
}