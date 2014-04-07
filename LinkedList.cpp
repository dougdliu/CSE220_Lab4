/*
 *CSE 220 Lab 4
 *LinkedList.cpp to implement LinkedList object
 *
 *
*/
#include "LinkedList.h"



LinkedList::LinkedList()
{
	line = 0;
	nextLine = NULL;	
	
	//default constructor
}
LinkedList::~LinkedList()
{
	//destructor
}
void LinkedList::addToList(int newLine)
{
	
	LinkedList *current;
	LinkedList *previous;
	
	LinkedList *newNode = new LinkedList;
	newNode->set(newLine);
	
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
		
	}
	
	
	
	
	
}
void LinkedList::printList()
{
	//traverse through the list and print the line numbers
	
	LinkedList *current;
	
	
	current = this;
	
	while(current != NULL)
	{
		//print the line number of the current node
		printf("%d\t", current->line);
		//set currentNode to the next node in te list
		current = current->nextLine;
	}
	
}
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
void LinkedList::set(int newLine)
{
	line = newLine;
}

