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
	
	LinkedList *currentNode;
	LinkedList *newNode = new LinkedList();
	newNode->line = newLine;
	newNode->nextLine = NULL;
	
	//check to see if the LinkedList object'list' is null
	if(lines == NULL)
	{
		lines = newNode;
		
	}
	else
	{
		currentNode = list;
		while(currentNode->nextLine != NULL)
		{
			currentNode = currentNode->nextLine;
		}
		currentNode->nextLine = newNode;
	}
	
}
void LinkedList::printList()
{
	//traverse through the list and print the line numbers
	
	LinkedList *current;
	current = lines;
	
	while(current != NULL)
	{
		//print the line number of the current node
		printf("%d\t", current->line);
		//set currentNode to the next node in te list
		current = current->nextLine;
	}
}

