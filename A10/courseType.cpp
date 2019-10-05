#include "courseType.h"

		/**************** CONSTRUCTORS *********************/
		// sectionId (int), courseName(string), title(string)
		//     14215		    CS 1B           INTRO TO COMP SCI II
		
		// day (string), time(string), room(string)
		//     MWF        8:00-9:50am   SM 346
		
		// status (bool), cap (int)
		courseType::courseType(string a , string b, string c, string d, string e, string f , bool g,  int h)
		{
			setSectionID(a);
			setCourseName(b);
			setTitle(c);
			setDays(d);
			setTime(e);
			setRoom(f);
			setStatus(g);
			setCap(h);
		}
				   
		courseType::courseType(courseType & x){
			setSectionID(x.getSectionID());
			setCourseName(x.getCourseName());
			setTitle(x.getTitle());
			setDays(x.getDays());
			setTime(x.getTime());
			setRoom(x.getRoom());
			setStatus(x.getStatus());
			setCap(x.getCap());
	
		}
		
	

		/***** setters *****/

		void courseType::setSectionID(string newID){
			sectionID = newID;
		}
		void courseType::setCourseName(string newName){
			courseName = newName;
		}
		void courseType::setTitle(string newTitle){
			title = newTitle;
			
		}
		void courseType::setDays(string newDay){
			day = newDay;
		}
		void courseType::setTime(string newTime){
			time = newTime;
		}
		void courseType::setRoom(string newRoom){
			room = newRoom;
		}
		void courseType::setStatus(bool newStatus){
			status = newStatus;
		}
		void courseType::setCap(int newCap){
			cap = newCap;
		}
		
	
		bool courseType::addStudent(){
		// Should only be called a student via their addCourse method
							// Used by a student attempting to
							// enroll in a course.
							// If enrolled != cap (hasn't reached max),
							//    1. enrolled increased by 1
							//    2. static incrementCensus method is called
							//    3. true result returned. 
							// else
							//	  1. false is returned
			if(enrolled != cap){
				enrolled++;
				
				return true;
			}
			else{
				return false;
			}
						
		}
		
		/***** getters *****/
		
		string courseType::getSectionID(){
			return sectionID;
		}
		string courseType::getCourseName(){
			return courseName;
		}
		string courseType::getTitle(){
			return title;
		}
		string courseType::getDays(){
			return day;
		}		
		string courseType::getTime(){
			return time;
		}
		string courseType::getRoom(){
			return room;
		}
		bool courseType::getStatus(){
			return status;
		}
		
		int courseType::getCap(){
			return cap;
		}
		int courseType::getEnrolled(){
			return enrolled;
		}
	
		
		void courseType::print(){		//prints all data of this class
			cout << "******************************************" << endl;
			cout << "Section ID: " << getSectionID() << endl; 
			cout << "Course Name: " << getCourseName() << endl;
			cout << "Title: " << getTitle() << endl; 
			cout << "Day: " << getDays() << endl;
			cout << "Time: " << getTime() << endl;
			cout << "Room: " << getRoom() << endl;
			cout << "Enrolled: " << getEnrolled() << endl;
			
		}
		
		void courseType::printStudents(){	//ONLY USED if doing the extra credit
								//    used by Professor when printing courses taught
						
		}



