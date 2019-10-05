#ifndef COLLEGETYPE_H
#define COLLEGETYPE_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class collegeType{
	private:
		string name;
		static int census;		
		
	public:
		collegeType();			//default constructor
		collegeType(string);	//pass name of the college as parameter
		
		void setName(string);	//set college name
		string getName();		//return the college name as a string
		void print();			//Prints a nice report with the College name and Census #

		//static functions
		static void increaseCensus(); // should only be called by a course objects after successfully
									  //  enrolling a student into a course
		static int getCensus();		  // can be called anywhere
	
};

#endif



