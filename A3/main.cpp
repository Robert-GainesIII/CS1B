#include "main.h"
#include <iostream>
#include <fstream>


void getData(string (&id)[4], string (&answers)[4], string (&grades)[4], char (&answerKey)[20]);

int main(){
	
	string answers[4];
	string grades[4];
	string studentID[4];
	char answerKey[20];
	getData(studentID, answers,grades, answerKey);
	 
}

void getData(string (&id)[4], string (&answers)[4], string (&grades)[4], char (&answerKey)[20]){
	
	ifstream fin; 
	fin.open("data.txt");
		if(fin){
			fin.getline(answerKey, 20);
				for(int i = 0; i < 4; i++){
				cout<< "Iteration " << i << endl;
					
					fin >> id[i];
					int score[4];
					char tempAnsw[20];
					
					for(int j= 0; j < 20; j++){
						
						char bit; 
						fin >> bit;
						tempAnsw[j] = bit;
						
						if(bit == answerKey[j])score[i]+=2;
						
						else if(bit == ' '){
							
						}
							
						else{
							score[i] --;
						}
						
						grades[i] = (score[i] / 20) * 100; 
						answers[i] = string(tempAnsw);
					
					}
					cout << id[i] << " " << answers[i] << " " << score[i] << " " << grades[i];
				}
			fin.close();
		}
}


