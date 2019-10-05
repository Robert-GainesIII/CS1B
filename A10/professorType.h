
#ifndef PROFESSOR_CLASS_HEADER
#define PROFESSOR_CLASS_HEADER
#include "personType.h"
#include "courseType.h"
#include <string>
#include <iostream>
#include <iomanip>

class professorType : public personType{
	
	private: 
	
	string employeeID;

    string department;

    string degree;
	
	courseType **schedule = nullptr;
	
	int courseCount = 0;
	
	public: 
	
	professorType();
	
	
	//       (firstN, lastN)
	professorType(string, string);
	
	
	//        (firstN, LastN,  Address, height, dob, gender, employeeID, department, degree);
	professorType(string, string, string, double, string, char, string, string, string);
	
	string getEmployeeID() const;
	string getDepartment() const;
	string getDegree() const;
	void getProfessorData(string &, string &, string &);
	
	void setEmployeeID(string);
	void setDepartment(string);
	void setDegree(string);
	void setProfessor(string, string, string);
	void setNumCourses(int);
	
	courseType ** getCourses();
	
	void addCourse(courseType *);
	
	void print() const;
};


#endif