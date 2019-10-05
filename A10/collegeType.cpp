#include "collegeType.h"

		int collegeType::census = 0;

		collegeType::collegeType(){		    //default constructor
			
		}
		collegeType::collegeType(string name){	//pass name of the college as parameter
			setName(name);
		}
		
		void collegeType::setName(string name){	//set college name
			setName(name);
		}
		string collegeType::getName(){  	//return the college name as a string
			return name;
		}
		void collegeType::print(){  		//Prints a nice report with the College name and Census #
			cout << "Census #: " << getCensus() << endl;
		}
		

		//static functions
		void collegeType::increaseCensus(){ // should only be called by a course objects after successfully
											//  enrolling a student into a course
			census++;								
		}
		int collegeType::getCensus(){       // can be called anywhere
			return census;
		}
	



