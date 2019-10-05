#ifndef CREDIT_HEADER
#define CREDIT_HEADER

#include <iostream>
using namespace std;

class creditCardType{
	
	private: 
	
	static int cardCount;
	static double creditLimit;
	static double balance;
	string cardNumber; 
	string name;
	string expiration;
	
	public:
	
	creditCardType(string);
	creditCardType(string,string);
	creditCardType(string,string,string);
	
	static int getCardCount();
	static double getCreditLimit();
	static double getBalance();
	string getCardNumber();
	string getName();
	string getExpiration();
	void getData(string &, string &, string &);
	
	void setCardNumber(string);
	void setName(string);
	void setExpiration(string);
	void setData(string,string,string);
	
	void purchase(float price);
	
	
	void print(){
		cout << "Name on File: " << name << endl;
		cout << "Card #: " << cardNumber << endl;
		cout << "Expiration Date: " << expiration << endl;
	};
	
	
};

#endif