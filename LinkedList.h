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
	
		//each LinkedList object will hold an int for line number
		//and a pointer to the next LinkedList object
		int line;
		LinkedList *nextLine;
	
		
	public:
		LinkedList();
		~LinkedList();
		void addToList(int line);
		void printList();
};

#endif
