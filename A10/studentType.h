#ifndef STUDENTTYPE_H_INCLUDED
#define STUDENTTYPE_H_INCLUDED
#include "personType.h"
#include "courseType.h"
#include <string>
#include <iostream>
#include <iomanip>

class studentType: public personType{
	private:
		int id; //added every id 'should' be unique
		double gpa;
		string classification;
		
		/** special **/
		int numCourses = 0;
	
		courseType **schedule; //is a dynamic array of courses (set size to 3 in your constructors).
		
	public:
		//constructors
		studentType();
		
		// fName, lName
		studentType(string, string);
		
		// fName, lName, GPA, classification, id
		studentType(string, string, double, string, int);

		//Student(firstName,lastName,addr,ht,dob,sex, gpa, year, id );
		studentType(string, string, string, double, string, char,
                 double, string, int);
	
	    void print() const; //override the parents' print method
		
		//setters
		void setGPA(double);
		void setID(int);
		void setClassification(string);
		void incrementNumCourses();
		
		// choose 1 addCourse proto below
		 bool addCourse( courseType *);
		
		
		//getters
		double getGPA();
		int getID();
		string getClassification();
		int getNumCourses();
};

#endif

