#include "main.h"
int main(){
	int playerCount = 0;
	playerType players[100];
	playerType sortedPlayers[100];
	cout << "Reading Data.." << endl;
	getData(players, playerCount);
	cout << "Copying Array.." << endl;
	for(int i = 0; i < 100; i++){
		sortedPlayers[i] = players[i];
	}

	cout << "Sorting Data.." << endl;
	sortData(players, playerCount);
	
	char c = '0';
	string search;
	int index;
	do{
		
		system("cls");
		cout << "************************************************************************************************" << endl;
		cout << "*Assignment: Exam1 Lab                                                                         *" << endl;
		cout << "*                                                                                              *" << endl;
		cout << "*                           `	                                                                 " << endl;
		cout << "*<1> Look up a player" << endl;
		cout << "*<2> Edit a Player" << endl;
		cout << "*<3> print League QB stats " << endl;
		cout << "*<4> Quit " << endl;                                                         
		cout << "*                                                                                               " << endl;
		cout << "************************************************************************************************" << endl;
		cout << "         Choice<1-4>:  ";
		
		cin >>c; 
		cin.ignore(20, '\n');
		cin.clear();
		
		switch(c){
			case '1': 
			cout << "Enter Player Name> ";
			cin >> search;
			index = lookUp(players, search, playerCount);
			if( index != -1){
				printTitle();
				printPlayer(players[index]);
				system("pause");
			}
			break;
			case '2': 
			edit(players, playerCount);
			break;
			case '3': 
			printTeam(players, playerCount);
			break;
			case '4': 
			
			break;
			default:
			cout << "enter valid input!" << endl;
			system("pause");
		}
		
	}while(c != '0');
	
return 0;
}

void getData(playerType (&players)[100], int &playerCount){
	
	ifstream fin;
	fin.open("players.txt");
	if(fin){
		int i = 0;
		while(!fin.eof()){
			
				fin >> players[i].id;
				fin >> players[i].fName;
				fin >> players[i].lName;
				fin >> players[i].gamesPlayed;
				fin >> players[i].completions;
				fin >> players[i].attempts;
				//fin >> players[i].completionPercent;
					fin >> players[i].passingYards;
				fin >> players[i].touchdownPasses; 
				fin >> players[i].interceptions;
				fin >> players[i].fumbles;
				fin >> players[i].team;
				//players[i].completionPercent = (players[i].completions/players[i].attempts)*1.0;
				playerCount++;
			i++;
		}
	}else{
		cout << "File was not Found! Terminating Program.";
	}
}

void sortData(playerType (&sorted)[100], int length){
	int index;
	int smallestIndex;
	int location;
	playerType temp;
	
	for(index = 0; index < length -1; index++){
		smallestIndex = index;
		for(location = index +1; location < length; location++){
			if(sorted[location].touchdownPasses < sorted[smallestIndex].touchdownPasses)
				smallestIndex = location;
		}
			
		temp = sorted[smallestIndex];
		sorted[smallestIndex] = sorted[index];
		sorted[index] = temp;
		
	}
}


void printPlayer(const playerType& player){
	cout << setw(200) << setfill('-') << '-' << endl;
	cout << setfill(' ');
	cout << setw(10) << left << player.id << setw(10) << left << player.fName <<setw(20) <<  player.lName <<  setw(15) << player.gamesPlayed << setw(15) << player.completions << setw(20) << player.attempts << setw(20) << player.completionPercent << setw(20) << player.passingYards << setw(20) << player.touchdownPasses << setw(10) << player.interceptions << setw(15) << player.fumbles << setw(15) << player.team << endl;
}

void printTitle(){
	cout << setw(10) <<left << "ID" << setw(30) << left << "Name" <<  setw(15) << "Games Played" << setw(15) << "Completions" << setw(20) << "attempts" << setw(20) << "pass %" << setw(20) << "Pass Yds" << setw(20) << "TD Passes" << setw(10) << "Ints" << setw(15) << "Fumbles" << setw(15) << "Team" << endl;
}

void printTeam(const playerType (&players)[100], int &playerCount){
	printTitle();
	for(int i = playerCount-1; i > 0; i--){
		printPlayer(players[i]);
	}
	
	system("pause");
	
}

int lookUp(playerType (&players)[100], string search, int &playerCount){
	string searchTemp = search;
	for(int i = 0; i < playerCount; i++){
		string playerNameTemp = players[i].fName; 
		string playerNameTemp2 = players[i].lName;
		toUpper(playerNameTemp2);
		toUpper(playerNameTemp);
		toUpper(searchTemp);
		//DEBUG LINES FOR SEEING COMPARISONS
		//cout << searchTemp  << "==" << bookTitleTemp <<endl;
		//system("pause");
		
		if(playerNameTemp.find(searchTemp) != string::npos || playerNameTemp2.find(searchTemp) != string::npos){
			cout << "Is this the player you were searching for?" << endl;
			cout << "RESULT >" << players[i].fName << " " << players[i].lName;
			cout << "(y/n)? > ";
			char c;
			cin >> c;
			if(c == 'y')
			return i;
		}
	}
	return -1;
	
}

void toUpper(string &str){
	for(int i = 0; i < str.length(); i++){
		if(str.at(i) >= 97 && str.at(i) <= 129){
			str.at(i) = str.at(i)-32;
			
		}
		
	}
}

void edit(playerType (&players)[100], int &playerCount){
	
		string search;
	
		system("cls");
		cout << "************************************************************************************************" << endl;
		cout << "*                                        SERENDIPITY BOOKSELLERS                               *" << endl;
		cout << "************************************************************************************************" << endl;	
		cout << "SEARCH >";
		cin >> search;
		int index = lookUp(players, search, playerCount);
		if(index > -1){
			cout<<"Is this the record you would like to edit?(y/n):";
			char c;
			cin >> c;
			if(c == 'y'){
				editRecord(players[index].id, players[index].fName, players[index].lName, players[index].gamesPlayed, players[index].completions,players[index].attempts, players[index].touchdownPasses, players[index].interceptions, players[index].passingYards, players[index].fumbles, players[index].team);
				sortData(players, playerCount);
			}
		}
}

void editRecord(int &id, string &fName, string &lName, int &gamesPlayed, int &completions, int &attempts, int &touchdownPasses, int &interceptions, int &passingYards, int &fumbles, string &team ){
	string tempName = "EMPTY";
	string tempAuthor = "EMPTY";
	string tempISBN = "EMPTY";
	string tempDate = "EMPTY";
	string tempPublisher = "EMPTY";
	int tempQty = 0;
	double tempWholesale = 0;
	double tempRetail= 0;
	char choice;
	string ch;

	do{
		//choice = ' ';
		system("cls");
		cout << "************************************************************************************************" << endl;
		cout << "*                                        SERENDIPITY BOOKSELLERS                               *" << endl;
		cout << "*                                               EDIT RECORD                                    *" << endl;
		cout << "*                                                                                              *" << endl;
		cout << "*                           `	                                                                 " << endl;
		cout << "*<a> ID                           > --" << id << "                                        " << endl;
		cout << "*<0> First Name                  > --" << fName  << "                                            " << endl;
		cout << "*<1> Last Name                   > --" << lName  << "                                          " << endl;
		cout << "*<2> Games Played                > --" << gamesPlayed  << "                                       " << endl;
		cout << "*<3> Completions                 > --" << completions  << "                                       " << endl;
		cout << "*<4> Attempts                    > --" << attempts  << "                                       " << endl;
		cout << "*<5> TouchdownPasses             > --" <<touchdownPasses  << "                                       " << endl;
		cout << "*<6> Interceptions               > --" << interceptions  << "                                          " << endl;
		cout << "*<7> Passing Yards               > --" << passingYards  << "                                          " << endl;
		cout << "*<8> Fumbles                     > --" << fumbles  << "                                          " << endl;
		cout << "*<9> Team                        > --" << team  << "                                          " << endl;
		cout << "*<e> Return To Inventory Menu                                                                   " << endl;
		cout << "*                                                                                               " << endl;
		cout << "************************************************************************************************" << endl;
		cout << "         Choice<0-8>:  ";
		
		cin >>choice; 
		cin.ignore(20, '\n');
		cin.clear();
		
		cout << ">>";
		switch(choice){
			
			case 'a':
			cin >> id;
			case '0': 
			cin >> fName;
			break;
			case '1': 
			cin >> lName;
			break;
			case '2': 
			cin >> gamesPlayed;
			break;
			case '3': 
			cin >> completions;
			break;
			case '4': 

			cin >> attempts;
			break;
			case '5': 
	
			cin >> touchdownPasses; 
			break;
			case '6': 
	
			cin >> interceptions;
			break;
			case '7': 
	
			cin >> passingYards;
			break;
			case '8': 
	
			cin >> fumbles;
			break;
			case '9': 
	
			cin >> team;
			break;
			
			case 'e':
			
			break;
			
			default: 
			cout << "Enter Valid Selection <0-9>!!!!!" << endl;
			system("pause");
		}
	}while(choice != 'e');
}