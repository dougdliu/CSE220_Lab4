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
void LinkedList::addToList(LinkedList **head, int newLine)
{
	
	LinkedList *currentNode;
	LinkedList *newNode = new LinkedList();
	newNode->line = newLine;
	newNode->nextLine = NULL;
	
	if((*head) == NULL)
	{
		(*head) = newNode;
	}
	else
	{
		//start at head of list and traverse to end
		currentNode = (*head);
		while(currentNode->nextLine != NULL)
		{
			currentNode = currentNode->nextLine;
		}
		//insert the new object at the end
		currentNode->next = newNode;
	}
	
}
void LinkedList::printList(LinkedList **head)
{
	//traverse through the list and print the line numbers
	
	LinkedList *current;
	current = (*head);
	
	while(current != NULL)
	{
		//print the line number of the current node
		printf("%d\t", current->line);
		//set currentNode to the next node in te list
		current = current->nextLine;
	}
}

