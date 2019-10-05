#include "personType.h"
	
	personType::personType(){
	}
	
	personType::personType(string a, string b){
		setFirstName(a);
		setLastName(b);
	}
	personType::personType(string a, string b, string c, double hght, string d, char gen){
		
		newPerson(a,b,c,hght,d,gen);
	}
	personType::personType(const personType &person){
		string tempFName, tempLName, tempAddress, tempDOB;
		double tempHeight;
		char tempChar;
		person.getPerson(tempFName, tempLName, tempAddress, tempHeight, tempDOB, tempChar);
		newPerson(tempFName, tempLName, tempAddress, tempHeight, tempDOB, tempChar);
	}

	void personType::newPerson(string newFName, string newLastName, string newAddress, double newHeight, string newDOB, char newGender){
		fName = newFName;
		lName = newLastName;
		address = newAddress;
		height = newHeight;
		dob = newDOB;
		gender = newGender;
	}

	void personType::setFirstName(string newFName){
		fName = newFName;
	}
		
	void personType::setLastName(string newLastName){
		lName = newLastName;
	}
		
	void personType::setAddress(string newAddress){
		address = newAddress;
	}

	void personType::setHeight(double newHeight){
		height = newHeight;
	}

	void personType::setDOB(string newDOB){
		dob = newDOB;
	}

	void personType::setGender(char newGender){
		gender = newGender;
	}
		
	string personType::getFirstName()const{
		return fName;
	}

	string personType::getLastName()const{
		return lName;
	}

	string personType::getAddress()const{
		return address;
	}

	double personType::getHeight()const{
		return height;
	}

	string personType::getDOB()const{
		return dob;
	}

	char personType::getGender()const{
		return gender;
	}
	
	
	void personType::getPerson(string &f, string &l, string &a, double &h, string &d, char &g)const{
		f = fName;
		l = lName;
		a = address;
		h = height;
		d = dob;
		g = gender;
	}

	void personType::print()const{
		cout << "********************************************" << endl;
		cout << "Person Details " << endl;
		cout << "First Name: " << fName << endl;
		cout << "Last Name: " << lName << endl;
		cout << "Address: " << address << endl;
		cout << "Player Height: " << height << endl;
		cout << "Date Of Birth: " << dob << endl;
		cout << "Gender: " << gender << endl;
		cout << "Mother: nullptr" << endl;
		cout << "Father: nullptr" << endl;
		cout << "********************************************" << endl << endl;
		
	}
	
	void personType::setMother(personType *a){
		
		
	}
	
	void personType::setFather(personType *b){
		
	}
	
	personType * personType::getMother() const {
		return mother;
	}
	
	personType * personType::getFather() const{
		return father;
	}