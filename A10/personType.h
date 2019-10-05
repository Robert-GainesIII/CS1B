#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class personType{
	private:
			string fName;
			string lName;
			string address;
			double height;
			string dob;
			char gender;
			personType *mother;
			personType *father;
	
	public: 
		/**************** CONSTRUCTORS *********************/

		//----------------------------------------------------
		// Function: personType()
		// Sets attributes of the person to default values
		// Receives: nothing
		// Returns: nothing
		//-----------------------------------------------------
		personType();
		
		//----------------------------------------------------
		// Function: Person(string f, string l)
		// Sets the first & last name of a person to the values 
		//   passed to it, and the remaining attributes to default
		//   values.
		// Receives:
		//  f:string
		//  l:string
		// Returns: nothing
		//-----------------------------------------------------			
		personType(string, string);
		
		//----------------------------------------------------
		// Function: Person(string f, string l, string a, int h, string dob, char g)
		// Sets the first/last name, address, height, dob, and gender of a person to the values 
		//   passed to it
		// Receives:
		//  f:string
		//  l:string
		//  a:string
		//  h:double
		//  dob:string
		//  g:char
		// Returns: nothing
		//-----------------------------------------------------			
		personType(string f, string l, string a, double h, string dob, char g);
		
		
		
		//personType(string = "not set", string = "not set", string = "not set", 
		       //double = 0, string = "not set", char = '\0');
		
		//----------------------------------------------------
		// Function: personType(otherPerson)
		// Copy constructor
		// Receives: otherPerson
		// Returns: nothing
		//-----------------------------------------------------
		personType(const personType &);		
		
		/***** setters *****/
		
		void newPerson(string, string,string, double, string, char);
		void getPerson(string &, string &,string &, double &, string &, char &)const;
		void setFirstName(string);
		void setLastName(string);
		void setAddress(string);
		void setHeight(double);
		void setDOB(string);
		void setGender(char);
		
		void setMother(personType *);
		void setFather(personType *);
		
		/***** getters *****/
		
		string getFirstName()const;
		string getLastName()const;
		string getAddress()const;
		double getHeight()const;
		string getDOB()const;
		char getGender()const;
		
		personType* getMother()const;
		personType* getFather()const;
		
		virtual void print() const; // Later for chapter 12 and polymorphism
		
		bool equals(personType &)const;

		/******** Destructor ***********/
		~personType(void){
			cout << "Object " << fName << " is being deleted" << endl;
		}
		
};

#endif

