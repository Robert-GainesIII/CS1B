#include "studentType.h"
		
        studentType::studentType(){
		}
        

        //fName, lName//
        studentType::studentType(string fName, string lName)
					:personType(fName,lName){
			schedule = new courseType *[3];
		}

        // fName, lName, GPA, classification, id //
        studentType::studentType(string fName, string lName, double GPA, string classification, int id)
					:personType(fName,lName){
			schedule = new courseType *[3];
			setGPA(GPA);
			setClassification(classification);
			setID(id);
		}
		
		//Student(firstName,lastName,addr,ht,dob,sex, gpa, year, id );
		studentType::studentType(string fName, string lName, string address, double height, string dob, char sex,double gpa, string year, int id)
				    :personType(fName, lName, address, height, dob, sex){
						
			schedule = new courseType *[3];			
			setGPA(gpa);
			setClassification(year);
			setID(id);
		
		}
        
              
        //setters
        void studentType::setGPA(double x){
			gpa = x;
		}
		
        void studentType::setID(int x){
			id = x;
			
		}
	
		
        void studentType::setClassification(string x){
			classification = x;
		}
        
        //getters
        double studentType::getGPA(){
			return gpa;
		}
		
        int studentType::getID(){
			return id;
		}
		
        string studentType::getClassification(){
			return classification;
		}
		
		int studentType::getNumCourses(){
			return numCourses;
		}
        
        //overridden methods
        void studentType::print() const{
			personType::print();
			
			cout << "STUDENT DETAILS: " << endl;
			cout << "ID: " << id << endl;
			cout << "GPA: "<< gpa << endl;
			cout << "CLASSIFICATION: "<< classification << endl;
			cout << "NUM OF CLASSES: " << numCourses << endl;
			cout << setw(10) << " " << setw(175) << setfill('-') << '-' << endl;
							cout << setfill(' ');
							cout << setw(10) << " " << left << setw(25) << "|SECTION ID" << setw(25) << "|COURSE" << setw(30) << "|TITLE" << setw(30) << "|DAYS/TIME" << setw(25) << "|ROOM " << setw(25) << "|ENROLLED " << setw(20) << "|CAP" << endl;
							for(int i = 0; i < numCourses; i++){
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
		
        // bool studentType::equals(studentType student){
			// return true;
		// }
        
		 bool studentType::addCourse(courseType *course){
			 if(numCourses <= 3){
				 if(course->addStudent()){
					 schedule[numCourses] = course;
					 incrementNumCourses();
					 return true;
				 }
			 }
			 return false;
		 }
        
		void studentType::incrementNumCourses(){
				numCourses++;
		}