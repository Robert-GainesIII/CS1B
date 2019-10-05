	#include "newClock.h"

	 ostream& operator<<(ostream&, const clockType&){
		 
	 }
     istream& operator>>(istream&, clockType&){
		 
		 
	 }

   void clockType::setTime(int hours, int minutes, int seconds){
		this->hours = hours;
		this->minutes = minutes;
		this->seconds = seconds;
   }
      //Function to set the member variables hr, min, and sec.  
      //Postcondition: hr = hours; min = minutes; sec = seconds

   void clockType::getTime(int& hours, int& minutes, int& seconds) const{
		hours = getHours();
		minutes = getMinutes();
		seconds = getSeconds();
   }
      //Function to return the time.
      //Postcondition: hours = hr; minutes = min; seconds = sec

    clockType clockType::operator++(){
		return new clockType(this->getHours(), this->getMinutes(), this->getSeconds() + 1);
	}
      //Overload the pre-increment operator.
      //Postcondition: The time is incremented by one second.

	clockType clockType::operator++(int){
		return *this; 
    }	
  	  // Overload the post increment operator
  	  // Postcondition: Time is incremented by one second.

    bool clockType::operator==(const clockType& otherClock) const{
		if(seconds == otherClock.getSeconds() && minutes == otherClock.getMinutes() && hours == otherClock.getHours()){
			return true;
		}
		else{
			return false;
		}
	}
      //Overload the equality operator.
      //Postcondition: Returns true if the time of this clock 
      //               is equal to the time of otherClock,
      //               otherwise it returns false.

    bool clockType::operator!=(const clockType& otherClock) const{
		if(seconds == otherClock.getSeconds() && minutes == otherClock.getMinutes() && hours == otherClock.getHours()){
			return false;
		}
		else{
			return true;
		}
	}
      //Overload the not equal operator.
      //Postcondition: Returns true if the time of this clock 
      //               is not equal to the time of otherClock,
      //               otherwise it returns false.

    bool clockType::operator<=(const clockType& otherClock) const{
		if(hours < otherclock.getHours())return true;
		else{
			if(hours == otherClock.getHours()){
				if(minutes < otherClock.getMinutes())return true;
				else{
					if(minutes == otherClock.getMinutes){
						if(seconds <= otherClock.getSeconds())return true
						else return false;
					}
				}
			}
		}
		return false;
	}
      //Overload the less than or equal to operator.
      //Postcondition: Returns true if the time of this clock
      //               is less than or equal to the time of 
      //               otherClock, otherwise it returns false.

    bool clockType::operator<(const clockType& otherClock) const{
	
	if(hours < otherclock.getHours())return true;
		else{
			if(hours == otherClock.getHours()){
				if(minutes < otherClock.getMinutes())return true;
				else{
					if(minutes == otherClock.getMinutes){
						if(seconds < otherClock.getSeconds())return true
						else return false;
					}
				}
			}
		}
		return false;
	}
      //Overload the less than operator.
      //Postcondition: Returns true if the time of this clock
      //               is less than the time of otherClock,
      //               otherwise it returns false.

    bool clockType::operator>=(const clockType& otherClock) const{
	
	if(hours > otherclock.getHours())return true;
		else{
			if(hours == otherClock.getHours()){
				if(minutes > otherClock.getMinutes())return true;
				else{
					if(minutes == otherClock.getMinutes){
						if(seconds >= otherClock.getSeconds())return true
						else return false;
					}
				}
			}
		}
		return false;
	}
      //Overload the greater than or equal to operator.
      //Postcondition: Returns true if the time of this clock
      //               is greater than or equal to the time of 
      //               otherClock, otherwise it returns false.

    bool clockType::operator>(const clockType& otherClock) const{
	
	if(hours > otherclock.getHours())return true;
		else{
			if(hours == otherClock.getHours()){
				if(minutes > otherClock.getMinutes())return true;
				else{
					if(minutes == otherClock.getMinutes){
						if(seconds > otherClock.getSeconds())return true
						else return false;
					}
				}
			}
		}
		return false;
	}
      //Overload the greater than operator.
      //Postcondition: Returns true if the time of this clock
      //               is greater than the time of otherClock,
      //               otherwise it returns false.

    clockType::clockType(int hours = 0, int minutes = 0, int seconds = 0){
		this->hours = hours;
		this->minutes = minutes;
		this->seconds = seconds;
	}
      //Constructor to initialize the object with the values 
      //specified by the user. If no values are specified,
      //the default values are assumed.
      //Postcondition: hr = hours; min = minutes; 
      //               sec = seconds;
	int clockType::getHours(){
		return hours;
	}
	int clockType::getMinutes(){
		return minutes;
	}
	int clockType::getSeconds(){
		return seconds;
	}
	
	// clockType::setHours(int hrs){
		// return hours;
	// }
	// clockType::setMinutes(int min){
		// return minutes;
	// }
	// clockType::setSeconds(int sec){
		// return seconds;
	// }