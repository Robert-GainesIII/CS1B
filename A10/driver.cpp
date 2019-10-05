//--------------------------------------------------------------------------//
//File Name: main.cpp
//Project Name: Exam Lab2
//--------------------------------------------------------------------------//
//Creator's name and email: Robert Gaines, gaines.robert.edgar@gmail.com
//Course-Selection: CS 1A Ticket # 80600
//Creation Date: 1/15/19
//Date of Last Modification: 3/6/19
//--------------------------------------------------------------------------//
//Purpose: Create a working example of our knowledge of pointers and classes
//--------------------------------------------------------------------------//
//Algorithm: 
//Step 1: Prompt user to enter max number of people and courses 
//step 2: Enter Menu
//OPTION 1: PROMPT USER FOR COURSE DATA AND CREATE NEW COURSE IF COURSE COUNT < NUMCOURSES

//OPTION 2: PROMPT USER FOR GENERIC PERSON AND CREATE ONE IF PERSONCOUNT < NUMPEOPLE

//OPTION 3: PROMPT USER FOR STUDENT DATA AND CREATE ONE IF STUDENTCOUNT < NUMSTUDENTS

//OPTION 4: PROMPT USER FOR PROFESSOR DATA AND CREATE ONE IF PROFESSORCOUNT < NUMPROFESSORS

//OPTION 5: ENROLL STUDENTS INTO COURSES

//OPTION 6: ASSIGN PROFESSORS TO COURSES

//OPTION 7: PRINT ALL COURSES

//OPTION 8: PRINT ALL PEOPLE

//OPTION 9: PRINT CENSUS

//OPTION 10: QUIT
//--------------------------------------------------------------------------//

//rows 						int 				null 						//
  
  #include "personType.h"
 #include "studentType.h"
 #include "professorType.h"
 #include "collegeType.h"
  #include "courseType.h"
  
  #include <iomanip>
  #include <string>
  
void printMenu();


int main(){
	
	//INIT TEMP VARIABLES THAT ARE USED TO READ IN USER DATA
	collegeType saddleback;
	string name;
	int census;
	string employeeID;
    string department;
    string degree;
	int id; //added every id 'should' be unique
	double gpa;
	string classification;
	string fName;
	string lName;
	string address;
	double height;
	string dob;
	char gender;
	int enrollChoice;
	int enrollChoice2;
	int index;
	int index2;
	
	int numPeople = 0;	// used to dynamically create people Array
	int numCourses = 0; // used to dynamically create courses Array
	int numStudents = 0; // used to dynamically create student Array
	int numProfessors = 0; // used to dynamically create professor Array
	
	int peopleCount = 0; // track # of people objects (includes Students, Professor, &GP)
	int studentCount = 0; // track # of students objects
	int courseCount = 0; // track # of course objects
	int professorCount = 0; // track # of professor objects
	
	char choice = '\0';
	
	personType **personArray = nullptr;
	courseType **coursesArray = nullptr;
	professorType **professorArray = nullptr;
	studentType **studentArray = nullptr;
	
	system("cls");
	
	cout << "How many people will be in the array?: ";
	
	cin >> numPeople;
	
	personArray = new personType *[numPeople];
	studentArray = new studentType *[numPeople];
	professorArray = new professorType *[numPeople];
	
	for(int i = 0; i < numPeople; i++)
	{
		studentArray[i] = nullptr;
		professorArray[i] = nullptr;
		personArray[i] = nullptr;
	}
	

	cout << "How many courses do you wish to offer?: ";
	cin >> numCourses;
	coursesArray = new courseType *[numCourses];
	
	for(int i = 0; i < courseCount; i++)
	{
		coursesArray[i] = nullptr;
	}
	
	do {
    
		system("cls");
		printMenu();
		cin >> choice;
		cin.ignore(5, '\n');
		
		string courseData[6];
		switch(choice)
		{
			case '1': // Create a new course
			cout << "Enter Section ID: ";
			getline(cin, courseData[0]);
			cout << "Enter Course Name: ";
			getline(cin, courseData[1]);
			cout << "Enter Course Title: ";
			getline(cin, courseData[2]);
			cout << "Enter days: "; 
			getline(cin, courseData[3]);
			cout << "Enter Time: ";
			getline(cin, courseData[4]);
			cout << "Enter Room: ";
			getline(cin, courseData[5]);
			
			if(courseCount != numCourses){
			coursesArray[courseCount] = new courseType(courseData[0],courseData[1],courseData[2],courseData[3],courseData[4], courseData[5]);
			courseCount++;
			}
			
			//CREATE NEW COURSE
				break;
			case '2': // create a new generic person
			cout << "Enter First Name: ";
			getline(cin, fName);
			cout << "Enter Last Name: ";
			getline(cin, lName);
			cout << "Enter Address: ";
			getline(cin,address);
			cout << "Enter Height: ";
			cin >> height;
			cin.ignore(20, '\n');
			cin.clear();
			cout << "Enter DOB: ";
			getline(cin, dob);
			cout << "Enter gender: ";
			cin >> gender;
			cin.ignore(20, '\n');
			cin.clear();
			
			if(peopleCount != numPeople){
			personArray[peopleCount] = new personType(fName, lName, address, height, dob, gender);
			peopleCount++;
			}
			
			//CREATE NEW GENERIC PERSON
				break;
			case '3': // create a new student
			cout << "Enter First Name: ";
			getline(cin, fName);
			cout << "Enter Last Name: ";
			getline(cin, lName);
			cout << "Enter Address: ";
			getline(cin,address);
			cout << "Enter Height: ";
			cin >> height;
			cin.ignore(20, '\n');
			cin.clear();
			cout << "Enter DOB: ";
			getline(cin, dob);
			cout << "Enter gender: ";
			cin >> gender;
			cin.ignore(20, '\n');
			cin.clear();
			cout << "Enter ID: ";
			cin >> id;
			cin.ignore(20, '\n');
			cin.clear();
			cout << "Enter GPA: ";
			cin >> gpa;
			cin.ignore(20, '\n');
			cin.clear();
			cout << "Enter Classifiacation: ";
			getline(cin, classification);
			
			if(peopleCount != numPeople){
			studentArray[studentCount] = new studentType(fName, lName, address, height, dob, gender, gpa, classification, id);
			personArray[peopleCount] = studentArray[studentCount];
			studentCount++;
			peopleCount++;
			}
			
				break;
			case '4': // create a new professor
			cout << "Enter First Name: ";
			getline(cin, fName);
			cout << "Enter Last Name: ";
			getline(cin, lName);
			cout << "Enter Address: ";
			getline(cin,address);
			cout << "Enter Height: ";
			cin >> height;
			cin.ignore(20, '\n');
			cin.clear();
			cout << "Enter DOB: ";
			getline(cin, dob);
			cout << "Enter gender: ";
			cin >> gender;
			cin.ignore(20, '\n');
			cin.clear();
			cout << "Enter Employee ID: ";
			getline(cin, employeeID);
			cout << "Enter Department: ";
			getline(cin, department);
			cout << "Enter degree: "; 
			getline(cin, degree);
			
			if(peopleCount != numPeople){
			professorArray[professorCount] = new professorType(fName, lName, address, height, dob, gender, employeeID, department, degree);
			professorArray[professorCount]->setNumCourses(numCourses);
			personArray[peopleCount] = professorArray[professorCount];
			professorCount++;
			peopleCount++;
			}
			
				break;
			case '5': // Enroll students into a course
				do{
					system("cls");
					cout << "ENROLLING STUDENTS" << endl;
					cout << "CURRENT STUDENT COUNT: " << studentCount << endl << endl;
					cout << setw(10) << " " << setw(100) << setfill('-') << '-' << endl;
					cout << setfill(' ');
					cout << left << setw(10) << " " << setw(25) << "|FIRST NAME" << setw(25) << "|LAST NAME" << setw(25) << "|COURSE LOAD" << setw(25) << "|MAX # COURSES  |" << endl;
					cout << setw(10) << " " << setw(100) << setfill('-') << '-' << endl;
					cout << setfill(' ');
					//PRINT OUT ALL STUDENTS
					for(int i = 0; i < studentCount; i++){
					cout << "<" << i+1 << setw(8) << left <<  ">" << "|" << setw(24) << studentArray[i]->getFirstName() << "|" << setw(24) << studentArray[i]->getLastName() << "|" <<  setw(24) << studentArray[i]->getNumCourses()  <<  "|" << setw(24) << numCourses << endl;
					}
					cout << setw(10) << " " << setw(100) << setfill('-') << '-' << endl << endl; 
					cout << setfill(' ');
					cout << "<R>eturn" << endl << endl;
					cout << "Choose student to enroll (1-" << studentCount << "):";
					
					cin >> enrollChoice;
					cin.ignore(20, '\n');
					cin.clear();
					
					if(enrollChoice != 0){
						do{
							index = enrollChoice-1;
							system("cls");
							cout << "ENROLLING - " << studentArray[index]->getFirstName() << endl<< endl;
							cout << "Current Course Count: " << studentArray[index] ->getNumCourses()  << endl << endl << endl;
							cout << setw(10) << " " << setw(175) << setfill('-') << '-' << endl;
							cout << setfill(' ');
							cout << setw(10) << " " << left << setw(25) << "|SECTION ID" << setw(25) << "|COURSE" << setw(30) << "|TITLE" << setw(30) << "|DAYS/TIME" << setw(25) << "|ROOM " << setw(25) << "|ENROLLED " << setw(20) << "|CAP" << endl;
							for(int i = 0; i < courseCount; i++){
								cout << "<" << i+1 << setw(8) << ">" << left <<  "|" << setw(24) << coursesArray[i]->getSectionID() << "|" << 
								setw(24) << coursesArray[i]->getCourseName() << "|" << 
								setw(29) << coursesArray[i]->getTitle() << "|" << 
								setw(29) << coursesArray[i]->getDays() << "|" <<
								setw(24) << coursesArray[i]->getRoom() << "|" << 
								setw(24) << coursesArray[i]->getEnrolled() << "|" <<
								setw(19) << coursesArray[i]->getCap() << "|" << endl;
							}
							cout << setw(10) << " " << setw(175) << setfill('-') << '-' << endl << endl;
							cout << setfill(' ');
							cout << "<0>Return" << endl << endl;
							cout << "Choose to enroll (1-" << courseCount << "):";
							cin >> enrollChoice2;
							cin.ignore(20, '\n');
							cin.clear();
							index2 = enrollChoice2-1;
							if(enrollChoice2 != 0){
								if(studentArray[index]->addCourse(coursesArray[index2])){
									collegeType::increaseCensus();
								}else{
									system("cls");
									cout << "Student Could Not Enroll Course!" << endl; 
									system("cls");
								}
							}
						}while(enrollChoice2 != 0);
						
					}
				
				}while(enrollChoice != 0);
				
				break;
			case '6': // Assign professor to a course
			
				do{
					system("cls");
					cout << "ENROLLING PROFESSOR" << endl;
					cout << "CURRENT PROFESSOR COUNT: " << professorCount << endl << endl;
					cout << setw(10) << " " << setw(100) << setfill('-') << '-' << endl;
					cout << setfill(' ');
					cout << left << setw(10) << " " << setw(25) << "|FIRST NAME" << setw(25) << "|LAST NAME" << setw(25) << "|DEPARTMENT" << setw(25) << "|MAX # COURSES  |" << endl;
					cout << setw(10) << " " << setw(100) << setfill('-') << '-' << endl;
					cout << setfill(' ');
					//PRINT OUT ALL STUDENTS
					for(int i = 0; i < professorCount; i++){
					cout << "<" << i+1 << setw(8) << left <<  ">" << "|" << setw(24) << professorArray[i]->getFirstName() << "|" << setw(24) << professorArray[i]->getLastName() << "|" <<  setw(24) << professorArray[i]->getDepartment()  <<  "|" << setw(24) << numCourses << endl;
					}
					cout << setw(10) << " " << setw(100) << setfill('-') << '-' << endl << endl; 
					cout << setfill(' ');
					cout << "<0>return" << endl << endl;
					cout << "Choose professor to enroll (1-" << professorCount << "):";
					
					cin >> enrollChoice;
					cin.ignore(20, '\n');
					cin.clear();
					index = enrollChoice-1;
					if(enrollChoice != 0){
						do{
							system("cls");
							cout << "ENROLLING - " << professorArray[index]->getFirstName() << endl<< endl;
							//cout << "Current Course Count: " << professorArray[index] ->getNumCourses()  << endl << endl << endl;
							cout << setw(10) << " " << setw(175) << setfill('-') << '-' << endl;
							cout << setfill(' ');
							cout << setw(10) << " " << left << setw(25) << "|SECTION ID" << setw(25) << "|COURSE" << setw(30) << "|TITLE" << setw(30) << "|DAYS/TIME" << setw(25) << "|ROOM " << setw(25) << "|ENROLLED " << setw(20) << "|CAP" << endl;
							for(int i = 0; i < courseCount; i++){
								cout << "<" << i+1 << setw(8) << ">" << left <<  "|" << setw(24) << coursesArray[i]->getSectionID() << "|" << 
								setw(24) << coursesArray[i]->getCourseName() << "|" << 
								setw(29) << coursesArray[i]->getTitle() << "|" << 
								setw(29) << coursesArray[i]->getDays() << "|" <<
								setw(24) << coursesArray[i]->getRoom() << "|" << 
								setw(24) << coursesArray[i]->getEnrolled() << "|" <<
								setw(19) << coursesArray[i]->getCap() << "|" << endl;
							}
							cout << setw(10) << " " << setw(175) << setfill('-') << '-' << endl << endl;
							cout << setfill(' ');
							cout << "<0>Return" << endl << endl;
							cout << "Choose to assign instructor to (0 - MaxNumber): ";
							cin >> enrollChoice2;
							cin.ignore(20, '\n');
							cin.clear();
							index2 = enrollChoice2 - 1;
							if(enrollChoice2 != 0){
								professorArray[index]->addCourse(coursesArray[index2]);
							}
						}while(enrollChoice2 != 0);
						
					}
				
				}while(enrollChoice != 0);
				break;
			case '7': 
				for(int i = 0; i < courseCount; i++){
					coursesArray[i]->print();
				}
				system("pause");
				break;
			case '8': // print all people in the personType array
				for(int i = 0; i < peopleCount; i++){
					personArray[i]->print();
				}
				system("pause");
				break;
			case '9': 
				cout << "Saddleback Valley College";
				saddleback.print();
				system("pause");
				break;
			default:
				break;
		}
		
	} while (choice != 'Q' && choice != 'q');	
	
	return 0;
}

void printMenu(){
	
	cout << "********************************************" << endl;
	cout << "<1>CREATE a new Course" << endl;
	cout << "<2>CREATE a new Genaric Person" << endl;
	cout << "<3>CREATE a new Student" << endl;
	cout << "<4>CREATE a new Professor" << endl;
	cout << "<5>Enroll a student in a course" << endl;
	cout << "<6>Assign a course to a professor" << endl;
	cout << "<7>Print ALL courses" << endl;
	cout << "<8>Print ALL people" << endl; 
	cout << "<9>Print SADDLEBACK census report" << endl;
	cout << "<Q> quit" << endl;
	cout << "********************************************* " << endl;
	cout << "Choice: ";
}
	
