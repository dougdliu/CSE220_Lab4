/*
 *Authors: Aaron Chasse, Jake Borg, Deming Liu
 *CSE 220 - Lab 4
 *04/09/2014
 *
 *Program Description:
 *LinkedList.cpp to implement LinkedList object. Each Token object will contain
 *one LinkedList object, and form a linked list representing the line numbers where
 *the token was found in the input file.
 *
*/


#include "LinkedList.h"


//Default constructor sets line to zero and pointer to next LinkedList object to NULL
LinkedList::LinkedList()
{
	line = 0;
	nextLine = NULL;	
}
//Free the heap memory for the LinkedList object
LinkedList::~LinkedList(){}

//This method will allocate memory on the heap for a new LinkedLit object
//to be part of the linked list of line numbers for the Token it is part of.
void LinkedList::addToList(int newLine)
{
	//LinkedList pointers for iterating through the list
	LinkedList *current;
	LinkedList *previous;
	
	//Create new instance of LinedList called newNode, set its line number to the incoming
	//integer
	LinkedList *newNode = new LinkedList;
	newNode->line = newLine;
	
	previous = NULL;
	
	if(this->nextLine == NULL)
	{
		
		this->nextLine = newNode;
		
	}
	else
	{
		current = this;
		while(current != NULL)
		{
			//printf("%d\n", current->line);
			previous = current;
			current = current->nextLine;
		}
		previous->nextLine = newNode;
		newNode->nextLine = current;
		
	}//end else block
	
}//end method addToList

//Traverse through the list and print the line numbers
void LinkedList::printList()
{
	
	LinkedList *current;
	current = this;
	
	while(current != NULL)
	{
		//print the line number of the current node
		printf("%d\t", current->line);
		//set currentNode to the next node in te list
		current = current->nextLine;
	}
	
}//end method printList

//Delete the list of LinkedLst objects
void LinkedList::deleteList()
{
	LinkedList *temp;
	temp = NULL;
	while(this->nextLine != NULL)
	{
		temp = this->nextLine;
		this->nextLine = temp->nextLine;
		delete temp;	
	}
}
void LinkedList::set(int line_number)
{
	this->line = line_number;
}
LinkedList* LinkedList::getNext() {
	return this->nextLine;
}
int LinkedList::getLine() {
	return this->line;
}
