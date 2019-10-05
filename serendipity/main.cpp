//--------------------------------------------------------------------------//
//File Name: main.cpp
//Project Name: Serendipity
//--------------------------------------------------------------------------//
//Creator's name and email: Robert Gaines, gaines.robert.edgar@gmail.com
//Course-Selection: CS 1A Ticket # 80600
//Creation Date: 1/15/19
//Date of Last Modification: 4/17/19
//--------------------------------------------------------------------------//
//Purpose: Create a working software application based on the chapters we 
//		   Discuss in class.
//--------------------------------------------------------------------------//
//Algorithm: 
//Step 1: Main Loop (1-4) Menu navigtion until termination
//1)CASHIER: 
//2)INVENTORY
//3)REPORTS
//4)QUIT
//--------------------------------------------------------------------------//
//-							Data Dictonary
//- CONSTANTS 
// NO CONSTANTS
//-
// VARIABLES
//
// NAME						DATA TYPE			INITIAL VALUE
// ----						---------			-------------  
//books 					bookType **			nullptr				//
//bookCount					static int 			0						//


#include "serendipity.h" 

//const int DBSIZE;
time_t h = time(NULL);


int main (){
	
	//int bookCount = 0;
	
	orderedLinkedList<bookType> books1,books2;
	
	
	char choice = '4';
	
	//https://stackoverflow.com/questions/23369503/get-size-of-terminal-window-rows-columns
	//USED TO OBTAIN SCREEN WIDTH AND HEIGHT
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;
	
	
	//READ IN BOOKS
	string title, isbn, author, publisher, dateAdded;
	int qtyOnHand;
	double wholesale, retail;
	ifstream dataIn;
	char c;
	
	dataIn.open("database.txt");
	cout << "Loading Prerequsuites..." << endl;
	do{
	
		getline(dataIn,title);
		getline(dataIn,isbn);
		getline(dataIn,author);
		getline(dataIn,publisher);
		getline(dataIn,dateAdded);
		dataIn >> qtyOnHand;
		dataIn >> wholesale;
		dataIn >> retail;
		dataIn.ignore();
		// dataIn.clear();
		bookType newBook(title,isbn,author,publisher,dateAdded,qtyOnHand,wholesale,retail,bookType::getBookCount());
		//cout << newBook;
		books1.insert(newBook);
		newBook.setSortCode(1);
		books2.insert(newBook);
		bookType::incBookCount();
	}while(!dataIn.eof());
	dataIn.close();
	
	cout << "Loaded "<< bookType::getBookCount() << " Books." << endl;
    system("pause");
	
	bookType::setDBSize(bookType::getBookCount());
  
	do{
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
		rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
		
		system("cls");
		cout << setfill(' ');
		
		
		cout << setw(columns/2) <<right <<  "Serendipity Bookstore" << endl; 
		cout << setw((columns/2) -5) << right << "Main Menu" << endl; 
		cout << ctime(&h) << endl;
		cout << "1. Cashier Module" << endl
			 << "2. Inventory Database Module" << endl
			 << "3. Report Module" << endl
			 << "4. Exit" << endl
			 <<	"Enter Your Choice:" << endl;
			
	    cin >> choice;
		system("cls");
		
		//sanitize input and flush cin buffer
		cin.clear();
		cin.ignore(20, '\n');
		
		switch(choice){
			
			case '1':
				cashier(books1);
			break;
			
			case '2': 
				inventory(books1);
			break;
			
			case '3':
				reports(books1);
			break;
			
			case '4':
			cout<<"Thank you for using Serendipity Bookstore. Please come again." << endl;
			system("pause");
			system("cls");
			break;
			
			case '&': 
			//bookInfo(bookTitle, isbn, author, publisher, dateAdded,qtyOnHand, wholesale, retail);
			break;
			
			default:
			cout << "Please enter valid input (1-4)" << endl;
			system("pause");
			
		}
		system("cls");
		
	}while(choice != '4');
	
}