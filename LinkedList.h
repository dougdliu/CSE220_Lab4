/*
 *Authors: Aaron Chasse, Jake Borg, Deming Liu
 *CSE 220 - Lab 4
 *04/09/2014
 *
 *Program Description:
 *Header file for LinkedList.cpp. Contains class definition, public and private variables and methods.
 *
*/

#ifndef _Lab4_LinkedList
#define _Lab4_LinkedList

#include <iostream>
#include "common.h"


using namespace std;

class LinkedList
{

	private:
	
		//each LinkedList object will hold an int for line number
		//and a pointer to the next LinkedList object
		int line;
		LinkedList *nextLine;
		LinkedList *current;		
		
	public:
		LinkedList();
		~LinkedList();
		void addToList(int newLine);
		void printList();
		void deleteList();
		void set(int line_number);
		/* for testing */
		LinkedList* getNext();
		int getLine();
};

#endif
