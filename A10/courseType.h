#ifndef COURSETYPE_H
#define COURSETYPE_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class courseType{
	private:
			string sectionID;
			string courseName;
			string title;
			string day;
			string time;
			string room;
			bool status; //true = not full, false = full
	
			
			int enrolled = 0; //This number is only incremented by the act of successfully
						  // enrolling a student in a course.
						  
			int cap; //constraint >= 0
		
			
	
	public: 
		/**************** CONSTRUCTORS *********************/
		// sectionId (int), courseName(string), title(string)
		//     14215		    CS 1B           INTRO TO COMP SCI II
		
		// day (string), time(string), room(string)
		//     MWF        8:00-9:50am   SM 346
		
		// status (bool), cap (int)
		courseType(string a = "not set", string b = "not set", string c = "not set", 
		           string d = "not set", string e = "not set", string f = "not set",
				   bool g = true,  int h = 30);
				   
		courseType(courseType &);
		
		/******** Destructor ***********/
		~courseType(void){
			cout << "Object is being deleted" << endl;
		}

		/***** setters *****/

		void setSectionID(string);
		void setCourseName(string);
		void setTitle(string);
		void setDays(string);
		void setTime(string);
		void setRoom(string);
		void setStatus(bool);
		void setCap(int);
		
		bool addStudent(); 	// Should only be called a student via their addCourse method
							// Used by a student attempting to
							// enroll in a course.
							// If enrolled != cap (hasn't reached max),
							//    1. enrolled increased by 1
							//    2. static incrementCensus method is called
							//    3. true result returned. 
							// else
							//	  1. false is returned
		
		/***** getters *****/
		
		string getSectionID();
		string getCourseName();
		string getTitle();
		string getDays();		
		string getTime();
		string getRoom();
		bool getStatus();
		int getCap();
		int getEnrolled();

		
		void print();			//prints all data of this class
		
		void printStudents(); 	//ONLY USED if doing the extra credit
								//    used by Professor when printing courses taught

};

#endif

