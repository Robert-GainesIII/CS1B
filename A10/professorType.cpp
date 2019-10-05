#include "professorType.h"

		professorType::professorType(){
			
		}
		
		
		//       (firstN, lastN)
		professorType::professorType(string firstName, string lastName)
					  :personType(firstName, lastName)
		{
			
		}
		
		
		//        (firstN, LastN,  Address, height, dob, gender, employeeID, department, degree);
		professorType::professorType(string firstName, string lastName, string address, double height, string DOB, char gender, string ID, string department, string degree)
					  :personType(firstName,lastName, address, height, DOB, gender)
		{
			setEmployeeID(ID);
			setDepartment(department);
			setDegree(degree);
		}
		
		string professorType::getEmployeeID() const{
			return employeeID;
		}
		
		string professorType::getDepartment() const{
			return department;
		}
		string professorType::getDegree() const{
			return degree;
		}
		
		void professorType::getProfessorData(string &x, string &y, string &z){
			x = employeeID; 
			y = department;
			z = degree;
		}
		
		void professorType::setEmployeeID(string str){
			employeeID = str;
		}
		void professorType::setDepartment(string str){
			department = str;
		}
		void professorType::setDegree(string str){
			degree = str;
		}
		void professorType::setProfessor(string x, string y, string z){
			
			employeeID = x;
			department = y;
			degree = z;
		}
		
		void professorType::print() const{
			personType::print();
	
			cout << "PROFESSOR DETAILS" << endl;
			cout << "employeeID: " << employeeID<< endl;
			cout << "department: "<< department << endl;
			cout << "degree: "<< degree << endl;
			cout << setw(10) << " " << setw(175) << setfill('-') << '-' << endl;
							cout << setfill(' ');
							cout << setw(10) << " " << left << setw(25) << "|SECTION ID" << setw(25) << "|COURSE" << setw(30) << "|TITLE" << setw(30) << "|DAYS/TIME" << setw(25) << "|ROOM " << setw(25) << "|ENROLLED " << setw(20) << "|CAP" << endl;
							for(int i = 0; i < courseCount; i++){
								cout << "<" << i+1 << setw(8) << ">" << left <<  "|" << setw(24) << schedule[i]->getSectionID() << "|" << 
								setw(24) << schedule[i]->getCourseName() << "|" << 
								setw(29) << schedule[i]->getTitle() << "|" << 
								setw(29) << schedule[i]->getDays() << "|" <<
								setw(24) << schedule[i]->getRoom() << "|" << 
								setw(24) << schedule[i]->getEnrolled() << "|" <<
								setw(19) << schedule[i]->getCap() << "|" << endl;
							}
							cout << setw(10) << " " << setw(175) << setfill('-') << '-' << endl << endl;
							cout << setfill(' ');
			cout << "********************************************" << endl;
			
		}
		
		void professorType::setNumCourses(int size){
			schedule = new courseType *[size];
		}
	
		void professorType::addCourse(courseType *x){
			schedule[courseCount] = x;
			courseCount++;
		}
		
		courseType ** professorType::getCourses(){
			return schedule;
		}
		
		