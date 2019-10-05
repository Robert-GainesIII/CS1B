//--------------------------------------------------------------------------//
//File Name: main.cpp
//Project Name: Sorting Wars A9
//--------------------------------------------------------------------------//
//Creator's name and email: Robert Gaines, gaines.robert.edgar@gmail.com
//Course-Selection: CS 1A Ticket # 80600
//Creation Date: 2/15/19
//Date of Last Modification: 2/19/19
//--------------------------------------------------------------------------//
//Purpose: Create an output display that shows the advantges and disadvantges 
//		   between the three sorting algortihms dicussed in this chapter
//--------------------------------------------------------------------------//
//Algorithm: 
//--------------------------------------------------------------------------//
//-							Data Dictonary
//- CONSTANTS 
// NO CONSTANTS
//-
// VARIABLES
//
// NAME						DATA TYPE			INITIAL VALUE
// ----						---------			-------------  

#include <iostream> 
#include <iomanip>
#include <fstream> 
using namespace std;

const int ARRSIZE = 200000;

void loadData(int (&data)[ARRSIZE]);
void selectionSort(int (&data)[ARRSIZE], int);
void insertionSort(int (&data)[ARRSIZE],int);
void bubbleSort(int (&data)[ARRSIZE],int);



int main(){
	
	int data0[ARRSIZE];
    system("cls");
	
	cout << "********************************************************************************************************" << endl;
	cout << "*                           Sorting Algorithms Comparisons                                             *" << endl;
	cout << "*                                        Metrics                                                       *" << endl;
	cout << "*                                    UNSORTED ARRAY                                                    *" << endl;
	
	const clock_t begin_time1 = clock();
	loadData(data0);
	cout<<"Calling Selection Sort....." << endl;
	selectionSort(data0, ARRSIZE);
	std::cout << float( clock () - begin_time1 ) /  CLOCKS_PER_SEC << endl;
	const clock_t begin_time2 = clock();
	loadData(data0);
	cout<<"Calling insertion Sort...." << endl;
	insertionSort(data0, ARRSIZE);
	std::cout << float( clock () - begin_time2 ) /  CLOCKS_PER_SEC << endl;
	const clock_t begin_time3 = clock();
	loadData(data0);
	cout<<"Calling Bubble Sort...." << endl;
	bubbleSort(data0, ARRSIZE);
	std::cout << float( clock () - begin_time3 ) /  CLOCKS_PER_SEC<< endl;
	
}

void loadData(int (&data)[ARRSIZE]){
	ifstream fin;
	fin.open("numbers.txt");
	if(fin){
	cout << "Loading Data...." << endl;
		for(int i = 0; i < ARRSIZE; i++){
		
			fin >> data[i]; 
			//fin >> holder;	
		}
		//cout << endl;
	}
	else{
		cout << "COULD NOT OPEN FILE!" << endl;
	}
	fin.close();
}

//WORKING 2/18/19 @ 11:00 PM
void selectionSort(int (&list)[ARRSIZE], int length){
	unsigned long long comparisons = 0;
	unsigned long long writes = 0;
	int time;
	int index;
	int smallestIndex;
	int location;
	int temp;
	
	for(index = 0; index < length -1; index++){
		smallestIndex = index;
		for(location = index +1; location < length; location++){
			comparisons++;
			if(list[location] < list[smallestIndex])
				smallestIndex = location;
	
		}
			
		temp = list[smallestIndex];
		writes++;
		list[smallestIndex] = list[index];
		writes++;
		list[index] = temp;
		writes++;
		
	}
	cout << "* Selection Sort - (C): " << comparisons << "          (W):" << writes << "                 TIME:";
}

void insertionSort(int (&list)[ARRSIZE],int length){
	unsigned long long comparisons = 0;
	unsigned long long writes = 0;
	for( int firstOutOfOrder = 1; firstOutOfOrder < length; firstOutOfOrder++){
		comparisons++;
		if(list[firstOutOfOrder] < list[firstOutOfOrder -1]){
			int temp = list[firstOutOfOrder];
			writes++;
			int location = firstOutOfOrder;
			writes++;
			do{
				list[location] = list[location -1];
				//writes++;
				location--;
				comparisons++;
			}while(location > 0 && list[location -1] > temp);
			writes++;
			list[location] = temp;
		}
	}
	cout << "* Selection Sort - (C): " << comparisons << "          (W):" << writes << "                 TIME:";
}

void bubbleSort(int (&list)[ARRSIZE],int length){
	unsigned long long comparisons = 0;
	unsigned long long writes = 0;
	
	for(int iteration = 1; iteration < length; iteration++){
		
		for(int index = 0; index < length - iteration; index++){
			
			comparisons++;
			
			if(list[index] > list[index + 1]){
				int temp = list[index];
				writes++;
				list[index] = list[index + 1];
				writes++;
				list[index + 1] = temp;
				writes++;
			}
		}
	}
	cout << "* Selection Sort - (C): " << comparisons << "          (W):" << writes << "                 TIME:";
}

