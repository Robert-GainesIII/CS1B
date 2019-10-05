#ifndef HEADER_FILE
#define HEADER_FILE
#include <iostream>
#include <iomanip> 
#include <string>
#include <fstream>
using namespace std;

struct playerType{
	
	int id;
	string fName;
	string lName;
	string team;
	int gamesPlayed;
	int completions;
	int attempts;
	double completionPercent;
	int touchdownPasses; 
	int interceptions;
	int passingYards;
	int fumbles;
	
};

void getData(playerType (&players)[100],int &playerCount);
void sortData(playerType (&sorted)[100] , int length);
void searchData(playerType (&players)[100]);
void printPlayer(const playerType& player);
int lookUp(playerType (&players)[100], string search,int &playerCount);
void toUpper(string &);
void printTeam(const playerType (&players)[100],int &playerCount);
void edit(playerType (&players)[100], int &playerCount);
void editRecord(int &id, string &fName, string &lName, int &gamesPlayed, int &completions, int &attempts,  int &touchdownPasses, int &interceptions, int &passingYards, int &fumbles, string &team );
void printTitle();
#endif 