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
void LinkedList::addToList(int *newLine)
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
void LinkedList::printList()
{
	//traverse through the list and print the line numbers
	LineList *currentNode;
	currentNode = head;
	
	while(currentNode != NULL)
	{
		//print the line number of the current node
		printf("%d\t", currentNode->line);
		//set currentNode to the next node in te list
		currentNode = currentNode->nextLine;
	}
}

