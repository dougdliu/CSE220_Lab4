/*





*/

#ifndef _Lab4_LinkedList
#define _Lab4_LinkedList

#include <iostream>
#include "common.h"
#include "Token.h"

using namespace std;

class LinkedList
{

	private:
		//initially the list in the token will be empty
		LineList *head = NULL;
		LineList *tail = NULL;
		//This struct will be used when the Token is an identifer and we 
		//need a linked list of integers. Each time the addToList metho is called
		//on the line number the token is on it will allocate memory for a new LineList
		//and insert it into the list. 
		typedef struct LineList{
			int line;
			LineList *nextLine;
		}LineList;
		
		
	public:
		LinkedList();
		~LinkedList();
		void addToList();
		void printList();
};

#endif
