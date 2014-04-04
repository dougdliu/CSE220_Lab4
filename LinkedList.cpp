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
void LinkedList::addToList(int newLine)
{
	
	
	LinkedList *newNode = new LinkedList();
	newNode->line = newLine;
	newNode->nextLine = NULL;
	
	if(head == NULL)
	{
		head = newNode;
	}
	else
	{
		//start at head of list and traverse to end
		currentNode = head;
		while(currentNode->nextLine != NULL)
		{
			currentNode = currentNode->nextLine;
		}
		//insert the new object at the end
		currentNode->next = newNode;
	}
	
}
void LinkedList::printList()
{
	//traverse through the list and print the line numbers
	
	currentNode = head;
	
	while(currentNode != NULL)
	{
		//print the line number of the current node
		printf("%d\t", currentNode->line);
		//set currentNode to the next node in te list
		currentNode = currentNode->nextLine;
	}
}

