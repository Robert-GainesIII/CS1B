
//Program that uses the class clockType.  
 
#include <iostream> 
#include "newClock.h" 
 
using namespace std;

int main()
{
    clockType myClock(5, 6, 23);                        //Line 1
    clockType yourClock;                                //Line 2

    cout << "Line 3: myClock = " << myClock << endl;    //Line 3
    cout << "Line 4: yourClock = " << yourClock
         << endl;                                       //Line 4

    cout << "Line 5: Enter time in the form "
         << "hrs:mins:secs ";                           //Line 5
    cin >> myClock;                                     //Line 6
    cout << "Line 7: New value of myClock = "
         << myClock << endl;                            //Line 7

    ++myClock;	                                        //Line 8

    cout << "Line 9: After increment myClock is "
         << myClock << endl;                            //Line 9

    yourClock.setTime(13, 35, 38);                      //Line 10
    cout << "Line 11: Now yourClock = "
         << yourClock << endl;                          //Line 11

    if (myClock == yourClock)                           //Line 12
        cout << "Line 13: myClock and yourClock "
         << "are equal" << endl;                        //Line 13
    else                                                //Line 14
        cout << "Line 15: myClock and yourClock "
             << "are not equal" << endl;	            //Line 15

    if (myClock <= yourClock)                           //Line 16
        cout << "Line 17: myClock is less than "
         << "yourClock" << endl;                        //Line 17
    else                                                //Line 18
        cout << "Line 19: myClock is not less "
         << "than yourClock" << endl;                   //Line 19

    cout << "Line 20: Testing post increment operator"
         << endl;                                       //Line 20

    yourClock = myClock++;                              //Line 21

    cout << "Line 22: myClock = " << myClock << endl;   //Line 22
    cout << "Line 23: yourClock = " << yourClock
         << endl;                                       //Line 23

    return 0;
}
