/*
 * Created By: Doug Liu
 * Description: This is the source file for the binary tree class.
 *
 */
 
#include "bTree.h"

bTree::bTree() //This is the constructor
{
  root = NULL;
}
bTree::~bTree() //This is the destructor
{
  destroy();
}
bTree::add(Token **token, int line) //This will add the identifier token either to the binary tree or adds page number to the linked list.
{
	Token *current;
	Token *previous;
	int foundAlready = FALSE;

	if(root == NULL)
	{
		root = (*token);
		root->leftChild = NULL;
		root->rightChild = NULL:
	}
	else
	{
		current = root;
		previous = root;

		while(current != NULL)
		{
			if(strcmp( (*token)->getString(),current->getString()) < 0)
			{
				//set the previous node pointer to the old node we're leaving
				previous = current;
				//set the current node pointer to the child node
				current = current->leftChild;
			}
			else if(strcmp( (*token)->getString(), current->getString()) > 0)
			{
				previous = current;
				current = current->rightChild;
			}
			else if(strcmp( (*token)->getString(), current->getString()) == 0)
			{
				(*token)->lines.addToList((*token)->lines, line);
				foundAlready = TRUE;
				break;
			}	
			
				
		}//end while loop
		
		//now current will be at either the left or right child of the node with a NULL child
		//previous will be looking at the parent node so we need to set its correct child node to be
		//pointing to the token that was passed in to the add function
		if(!foundAlready)
		{
			if(strcmp( (*token)->getString(), previous->getString()) < 0)
			{
				previous->leftChild = (*token);
				(*token)->lines.addToList((*token)->lines, line);
				(*token)->leftChild = NULL;
				(*token)->rightChild = NULL;
			}
			else
			{
				previous->rightChild = (*token);
				(*token)->lines.addToList((*token)->lines, line);
				(*token)->leftChild = NULL;
				(*token)->rightChild = NULL;
			}
		}
		
	}//end else block


}//end add method
