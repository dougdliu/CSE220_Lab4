/*
 *CSE 220 Lab 4
 *LinkedList.cpp to implement LinkedList object
 *
 *
*/

LinkedList::LinkedList()
{
	//default constructor
}
LinkedList::~LinkedList()
{
	//destructor
}
LinkedList::addToList(int *newLine)
{
	LineList *newNode = new LineList;
	newNode->line = newLine;
	newNode->nextLine = NULL;
	
	if(head == NULL)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->nextLine = newNode;
		tail = newNode;
	}
	
	
	
}

