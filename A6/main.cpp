//--------------------------------------------------------------------------//
//File Name: main.cpp
//Project Name: A6
//--------------------------------------------------------------------------//
//Creator's name and email: Robert Gaines, gaines.robert.edgar@gmail.com
//Course-Selection: CS 1A Ticket # 80600
//Creation Date: 2/8/19
//Date of Last Modification: 2/11/19
//--------------------------------------------------------------------------//
//Purpose: Create a working software application that shows visible differences
//		   between sorting and search alorithms discussed in classs
//--------------------------------------------------------------------------//
//Algorithm: 
//Step 1: Main Loop (1-4) Menu navigtion until termination
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

void loadData(int (&data)[200000], ifstream &fin);
void sortArray(int (&data)[200000], int size, bool &sorted);
int linearSearch(int (&data)[200000], int arraySize, int target, int &numComparisons);
int binarySearch(int (&data)[200000], int arraySize, int target, int &numComparisons);

int main(){
	int x, y = 0;
	bool sorted = false;
	int data[200000];
	int sortedData[200000];
	int target;
	int linearCompare;
	int binaryCompare;
	ifstream fin;
	fin.open("numbers.txt");
	if(fin){
	loadData(data, fin);
	cout << data;
	char choice;
		while(choice != '4'){
			system("cls");
			cout<<"*************** A6 ****************" << endl;
			cout<<"*CURRENT TARGET: " << target <<"                *"<< endl;
			cout<<"*            Search Times         *" << endl;
			cout<<"*Linear:" <<linearCompare<<"	comparisons       *" << endl;
			cout<<"*Binary:" <<binaryCompare<<"	comparisons       *" << endl;
			cout<<"*                                 *" << endl;
			cout<<"*<1> Enter integer to search      *" << endl;
			cout<<"*<2> Linear Search                *" << endl;
			cout<<"*<3> Binary Search                *" << endl;
			cout<<"*<4> Quit                         *" << endl;
			cout<<"*" << endl;
			cout<<"Choose from the menu (1-4): ";
			cin >> choice;
				switch(choice){
					case '1':
						cout << endl << "Enter new Target: ";
						cin >> target;
					break;
					case '2': 
						x = linearSearch(data, 200000 , target, linearCompare);
						cout << "Done with linear search";
						if(x != -1){
							cout << "Target found at index: " << x <<endl;
						}
						else{
							cout << "Target not found!" << endl;
						}
						system("pause");
						break;
					case '3': 
						if(!sorted){
						cout << "The array must first be sorted" << endl;
						cout << "Sorting now..." << endl;
						sortArray(data, 200000, sorted);
						}
						y = binarySearch(sortedData, 200000, target, binaryCompare);
						if(y != -1){
							cout << "Target found at index: " << y <<endl;
						}
						else{
							cout << "Target not found!" << endl;
						}
						system("pause");
					break;
					case '4':
						cout << "Exiting Program.." << endl;
					break;
					default:
						cout << "INVALID INPUT ENTER (1-4)!" <<endl;
				}
			}
	}
	else {
		cout << "File 'numbers.txt'was not found.." << endl;
	}
	
}

void loadData(int (&data)[200000], ifstream &fin){
	char holder;
	
	while(!fin.eof()){
		for(int i = 0; i < 200000; i++){
		
			fin >> data[i]; 
			//fin >> holder;
			
		}
		//cout << endl;
	}
}

int linearSearch(int (&data)[200000], int arraySize , int target,  int &numComparisons){
	
	int index = -1;
	
	 for(int i = 0; i < arraySize; i++){
		 numComparisons++;
		 //cout << data[i] << " = " << target << endl;

		 if(data[i] == target){
			 cout << data[i] << " = " << target << endl;
			 system("pause");
			 return i;
		 }
		
	 }
	 return index;
}

int binarySearch(int (&data)[200000], int arraySize , int target,  int &numComparisons){
	
	int index = -1;
	
	int f,l,m;
    f=0;
    l=arraySize-1;
    
    while(f<=l)
    {
		numComparisons++;
        m=(f+l)/2;
        if(target==data[m])
            return(m);
        else{
			numComparisons++;
            if(target>data[m])
                f=m+1;
            else
                l=m-1;
		}
    }
    
    return index;
}

void sortArray(int (&data)[200000], int size, bool &sorted){
	int i, temp = 0;
	for(int i= 0; i < size; i++){
		if(data[i] > data[i + 1]){
		    temp = data[i];
			data[i] = data[i+1];
			data[i+1] = temp;
		}
	}
	cout << "Array Sorted!" << endl;
	system("pause");
	sorted = true;
}


