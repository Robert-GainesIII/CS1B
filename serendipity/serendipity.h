#include<iostream>
#include<windows.h>
#include<iomanip>
#include<ctime> 
#include<fstream> 
#include "orderedLinkedList.h"
using namespace std;

#ifndef SERENDIPITY_HEADER
#define SERENDIPITY_HEADER


class bookType{
	int sortcode;
	friend ostream& operator << (ostream&, const bookType&);
	
	string bookTitle;
	string isbn;
	string author;
	string publisher;
	string dateAdded;
	int qtyOnHand;
	int checkoutTotal;
	int index;
	double wholesale;
	double retail;
	static int bookCount;
	static int DBSIZE;
	
	void setIndex(int);
	
	public: 
	bookType();
	bookType(string, string,string,string,string, int , double, double, int);
	void setBookTitle(string);
	void setISBN(string);
	void setAuthor(string);
	void setPublisher(string);
	void setDateAdded(string);
	void setQtyOnHand(int);
	void setWholesale(float);
	void setRetail(float);
	void setSortCode(int);
	void addToCheckoutTotal(int);
	static void incBookCount();
	static void decBookCount();
	static void setDBSize(int);
	
	int month;
	int day;
	int year;
	
	void print();
	bool equals(bookType);
	bool operator==(const bookType& otherBook)const;
	bool operator>=(const bookType& otherBook)const;
	
	string getBookTitle() const;
	string getISBN() const;
	string getAuthor()const;
	string getPublisher()const;
	string getDateAdded()const;
	int getQtyOnHand()const;
	int getIndex()const;
	int getCheckoutTotal()const;
	int getSortCode()const;
	double getWholesale()const;
	double getRetail()const;
	static int getBookCount();
	static int getDBSIZE();
};

inline ostream& operator<< (ostream& osObject, const bookType& books)
{
	osObject << "Title " << books.getBookTitle() << endl;
	osObject << "ISBN " << books.getISBN() << endl;
	osObject << "Author: " << books.getAuthor() << endl;
	osObject << "Publisher: " << books.getPublisher() << endl;
	osObject << "Date Added: " << books.getDateAdded() << endl;
	osObject << "Quantity on Hand: " << books.getQtyOnHand() << endl;
	osObject << "Wholesale Cost: " << books.getWholesale() << endl;
	osObject << "Retail Price: " << books.getRetail() << endl;
	system("pause");
	return osObject;

}

bool inline bookType::operator>= (const bookType& otherBook)const
{
	bool found = false;
	bool greaterThan = false;
	string temp1 = this->getBookTitle();
	string temp2 = otherBook.getBookTitle();
	string one;
	string two;
	int oneTemp = 0;
	int twoTemp = 0;
	
	if(this != &otherBook){
		switch(otherBook.getSortCode()){
			case 0:
				if(temp1.compare(temp2) >= 0)
					found = true;
				break;
			case 1:
			
				if(this->getQtyOnHand() <= otherBook.getQtyOnHand())
				{
					found = true;
				}
				break;
			case 2:
			
				if(this->getWholesale() <= otherBook.getWholesale())
				{
					found = true;
				}
				break;
			case 3:
			
				greaterThan = false;
				one = this->getDateAdded().substr(6,10);
				oneTemp = atoi(one.c_str());
				
				two = otherBook.getDateAdded().substr(6,10);
				twoTemp = atoi(two.c_str());
				
				if (oneTemp > twoTemp)
					greaterThan = true;
				else{
					if (oneTemp == twoTemp)
					{
						one = this->getDateAdded().substr(0,2);
						oneTemp = atoi(one.c_str());
						
						two = otherBook.getDateAdded().substr(0.2);
						twoTemp = atoi(two.c_str());
						
						if (oneTemp > twoTemp)
							greaterThan = true;
						else{
							if (oneTemp == twoTemp)
							{
								one = this->getDateAdded().substr(3,5);
								oneTemp = atoi(one.c_str());
								
								two = otherBook.getDateAdded().substr(3,5);
								twoTemp = atoi(two.c_str());
								
								if(oneTemp > twoTemp)
									greaterThan = true;
							}
						}
					}
				}
			break;
		}
	}
	
	return greaterThan;
}

bool inline bookType::operator==(const bookType& otherBook)const{
			if(this->getBookTitle() == otherBook.getBookTitle() &&
			   this->getISBN() == otherBook.getISBN() &&
			   this->getAuthor() == otherBook.getAuthor() && 
			   this->getPublisher() == otherBook.getPublisher() &&
			   this->getDateAdded() == otherBook.getDateAdded() &&
			   this->getQtyOnHand() == otherBook.getQtyOnHand() &&
			   this->getWholesale() == otherBook.getWholesale() &&
			   this->getRetail() == otherBook.getRetail())return true;
			return false;
	}



bookType lookUp(orderedLinkedList<bookType> &);

void cashier(orderedLinkedList<bookType> &);
void inventory(orderedLinkedList<bookType> &);
//void bookInfo(const bookType &);
//void bookListing(orderedLinkedList<bookType> &);
void reports(orderedLinkedList<bookType> &);

void toUpper(string &);

#endif


