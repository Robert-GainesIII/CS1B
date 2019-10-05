#ifndef H_UNORDEREDLINKEDLISTS
#define H_UNORDEREDLINKEDLISTS

#include <iostream>
#include <cassert>

#include "linkedlist.h"


using namespace std;

template <class Type> 
class unorderedLinkedList: public linkedListType <Type> 
{ 
	using linkedListType<Type>::head;
	using linkedListType<Type>::tail;
	using linkedListType<Type>::count;
	
public: 


bool search(const Type& searchItem) const; 
//Function to determine whether searchItem is in the list. 
//Postcondition: Returns true if searchItem is in the 
// list, otherwise the value false is  
// returned.
void inserthead(const Type& newItem); 
//Function to insert newItem at the beginning of the list. 
//Postcondition: head points to the new list, newItem is 
// inserted at the beginning of the list,
// tail points to the tail node in the 
// list, and count is incremented by 1.
void inserttail(const Type& newItem); 
//Function to insert newItem at the end of the list. 
//Postcondition: head points to the new list, newItem 
// is inserted at the end of the list, 
// tail points to the tail node in the 
// list, and count is incremented by 1.
void deleteNode(const Type& deleteItem); 
//Function to delete deleteItem from the list. 
//Postcondition: If found, the node containing
// deleteItem is deleted from the list. 
// head points to the head node, tail 
// points to the tail node of the updated 
// list, and count is decremented by 1.

};

template <class Type> 
bool unorderedLinkedList<Type>::search(const Type& searchItem) const 
{ 
nodeType<Type> *current; //pointer to traverse the list 
bool found = false; 
current = head; //set current to point to the head node in the list

while (current != nullptr && !found) //search the list 
if (current->info == searchItem) //searchItem is found 
	found = true; 
else 
	current = current->link; //make current point to //the next node 
return found; }
//end search

template <class Type> 
void unorderedLinkedList<Type>::inserthead(const Type& newItem) 
{ 
	nodeType<Type> *newNode; //pointer to create the new node 
	newNode = new nodeType<Type>; //create the new node 
	newNode->info = newItem; //store the new item in the node
	newNode->link = head; //insert newNode before head 
	head = newNode; //make head point to the //actual head node 
	count++; //increment count
	if (tail == nullptr) //if the list was empty, newNode is also //the tail node in the list 
		tail = newNode; 
}//end inserthead

template <class Type> 
void unorderedLinkedList<Type>::inserttail(const Type& newItem) 
{ 
nodeType<Type> *newNode; //pointer to create the new node
newNode = new nodeType<Type>; //create the new node 
newNode->info = newItem; //store the new item in the node 
newNode->link = nullptr; //set the link field of newNode //to nullptr
if (head == nullptr) //if the list is empty, newNode is //both the head and tail node 
{ 
head = newNode; 
tail = newNode; 
count++; //increment count 
} 
else //the list is not empty, insert newNode after tail 
{
	tail->link = newNode; //insert newNode after tail
	tail = newNode; //make tail point to the actual //tail node in the list 
	count++; //increment count 
	} 
}//end inserttail


template <class Type> 
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem) 
{ 
nodeType<Type> *current; //pointer to traverse the list 
nodeType<Type> *trailCurrent; //pointer just before current 
bool found;
if (head == nullptr) //Case 1; the list is empty 
	cout << "Cannot delete from an empty list." << endl; 
	else 
	{ 
		if (head->info == deleteItem) //Case 2 
		{ 
		current = head; 
		head = head->link; 
		count--;
		if (head == nullptr) //the list has only one node 
			tail = nullptr;
		delete current;
} 
else //search the list for the node with the given info 

{ 
found = false; 
trailCurrent = head; //set trailCurrent to point //to the head node 
current = head->link; //set current to point to //the second node
while (current != nullptr && !found) 
{ 
if (current->info != deleteItem) 
{ 
trailCurrent = current; 
current = current-> link; 
} 
else 
	found = true; 
}//end while

if (found) //Case 3; if found, delete the node 
{ 
trailCurrent->link = current->link; 
count--;
if (tail == current) //node to be deleted //was the tail node 
tail = trailCurrent; //update the value //of tail 
delete current; //delete the node from the list
} 
else
cout << "The item to be deleted is not in " << "the list." << endl; 
		}//end else 
	}//end else 
}//end deleteNode




#endif