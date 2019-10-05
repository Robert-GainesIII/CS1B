
#ifndef HEADER_MAINFILE
#define HEADER_MAINFILE
#include <string> 

const int COLSIZE = 2;
const int ROWSIZE = 12;
std::string MONTHS[] = {"January", "Febuary", "March",
						 "April", "May", "June", 
						 "July", "August", "September",
						 "October", "November", "December"};

void getData (int (&data)[ROWSIZE][COLSIZE]);

int averageHigh(const int (&data)[ROWSIZE][COLSIZE]);

int averageLow(const int (&data)[ROWSIZE][COLSIZE]);

void indexHighTemp(const int (&data)[ROWSIZE][COLSIZE], int &row, int &col);

void indexLowTemp(const int (&data)[ROWSIZE][COLSIZE], int &row, int &col);



#endif 