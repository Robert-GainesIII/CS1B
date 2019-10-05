//
// Created by coolr on 1/20/2019.
//

#ifndef A1_SERENDIPITY_SERENDIPITY_H
#define A1_SERENDIPITY_SERENDIPITY_H

#include "windows.h"
#include <iostream>
#include <iomanip>
using namespace std;

const int DBSIZE = 20;

void cashier();
void mainMenu(string[], string[], string[], string[], string[], int[], double[], double[],int(&));
void invMenu(string[], string[], string[], string[], string[], int[], double[], double[],int(&));
void reports();
void bookInfo(string[], string[], string[], string[], string[], int[], double[], double[]);


void lookUpBook(string[], string[], string[], string[], string[], int[], double[], double[], int (&)); //looks up book function
void addBook(string[], string[], string[], string[], string[], int[], double[], double[], int (&)); //add book function
void editBook(); //edit book function
void deleteBook(); //delete book function

void repListing(); //reports by listing function
void repWholesale(); //wholesale reports function
void repRetail(); //retail reports function
void repQty(); //quantity reports function
void repCost(); //cost reports function
void repAge(); // age reports function


#endif //A1_SERENDIPITY_SERENDIPITY_H
