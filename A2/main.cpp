#include "main.h"
#include <fstream> 
#include <iostream> 
#include <iomanip> 
using namespace std;

int main(){
	
	int weather[12][2];
	getData(weather);
	cout <<"Yearly Statistics: " << endl << endl;
	cout <<"Average Hi: " << averageHigh(weather) << "\370" << endl << endl;
	cout <<"Average Low: " << averageLow(weather) << "\370" << endl << endl;
	
	int row, col = 0;
	indexHighTemp(weather, row, col);
	cout <<"Highest Tempature: " << weather[row][col] << "\370" << "\tMonth: " << MONTHS[row];
	
	int row2, col2 = 0;
	indexLowTemp(weather, row2, col2);
	cout <<"Lowest Tempature: " << weather[row2][col2] << "\370" << "\tMonth: " << MONTHS[row2];
	
	return 0;
}
void getData(int (&data)[ROWSIZE][COLSIZE]){
	
	ifstream fin;
	fin.open("data.txt");
	if(fin){
		
		for(int row = 0; row < 12; row++){
			for(int col = 0; col < 2; col++){
				fin >> data[row][col];
				cout<< data[row][col] << endl;
			}
		}
		
	}fin.close();
}
	
int averageHigh(const int (&data)[ROWSIZE][COLSIZE]){
	int avgHigh = 0;
	for(int row = 0; row < ROWSIZE; row++){
			
				avgHigh += data[row][0];
			
	}
	
	return avgHigh/12;
	
}

int averageLow(const int (&data)[ROWSIZE][COLSIZE]){
	int avgLow= 0;
	for(int row = 0; row < ROWSIZE; row++){
			
				avgLow += data[row][1];
			
	}
	return avgLow/12;
}

void indexHighTemp(const int (&data)[ROWSIZE][COLSIZE], int &rowIndex, int &colIndex){
	int highest = 0;
	for(int row = 0; row < 12; row++){
		for(int col = 0; col < 2; col++){
			if(data[row][col] > highest){
				highest = data[row][col];
				rowIndex = row;
				colIndex = col;
			}
		}
	}
}
void indexLowTemp(const int (&data)[ROWSIZE][COLSIZE] , int &rowIndex, int &colIndex){
	int lowest = 0;
	for(int row = 0; row < 12; row++){
		for(int col = 0; col < 2; col++){
			cout << "row: " << row << endl;
			if(lowest > data[row][1]){
				lowest = data[row][1];
				rowIndex = row;
				colIndex = 1;
			}
		}
	}
}

