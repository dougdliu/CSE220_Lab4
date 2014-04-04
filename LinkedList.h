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
