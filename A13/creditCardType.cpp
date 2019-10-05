#include "creditCardType.h" 
	 int creditCardType::cardCount = 0;	
	 double creditCardType::creditLimit = 10000;
	 double creditCardType::balance = 0;

	creditCardType::creditCardType(string name){
		cardCount++;
		setName(name);
		cout << "Card Count : " << cardCount << endl;
	}
	
	creditCardType::creditCardType(string name,string cardNum){
		cardCount++;
		setName(name);
		setCardNumber(cardNum);
		cout << "Card Count : " << cardCount << endl;
	}
	
	creditCardType::creditCardType(string name,string cardNumber,string expiration){
		cardCount++;
		setName(name);
		setCardNumber(cardNumber);
		setExpiration(expiration);
		cout << "Card Count : " << cardCount << endl;
	}
	
    int creditCardType::getCardCount(){
		return cardCount;
	}
	
    double creditCardType::getCreditLimit(){
		return creditLimit;
	}
	double creditCardType::getBalance(){
		return balance;
	}
	
	string creditCardType::getCardNumber(){
		return cardNumber;
	}
	
	string creditCardType::getName(){
		return name;
	}
	string creditCardType::getExpiration(){
		return expiration;
	}
	
	void creditCardType::getData(string &nameVar, string &numVar, string &expirationVar){
		nameVar = name;
		numVar = cardNumber;
		expirationVar = expiration;
	}
	
	void creditCardType::setCardNumber(string newCardNum){
		cardNumber = newCardNum;
	}
	void creditCardType::setName(string newName){
		name = newName;
	}
	void creditCardType::setExpiration(string newExpiration){
		expiration = newExpiration;
	}
	void creditCardType::setData(string name,string cardNum ,string exp){
	
		setName(name);
		setCardNumber(cardNum);
		setExpiration(exp);
	}
	
	void creditCardType::purchase(float price){
		
		if(balance+price < creditLimit){
			balance += price;
			print();
			cout << name << " spent " << price  << " dollars." << endl;
			cout << "Current Balance: " << balance << endl;
			
		}else{
			
			cout << "Purchase exeeded credit limit! purchase was cancled" << endl;
		}
		
	}