/*
 * Created By: Doug Liu
 * Description: This is the source file for the binary tree class.
 *
 */

#include "bTree.h"

bTree::bTree() //This is the constructor
{
  root = NULL;//sets root to NULL
}
bTree::~bTree() //This is the destructor
{
  destroy();//calls the destroy method to destroy the tree
}
void bTree::add(Token **token, int line) //This either sets the root node or calls the recursive add node
{
	if(root != NULL)//If root is not empty, it will recursively call the recursive add method
	{
		rAdd(*token, root, line); //This add has the wrong parameters, we need to fix this.
	}
	else
	{
		root = new node; //creates a new node called root
		root->treeNode = (*token); //sets the root node to pointer of token
		root->leftChild = NULL; //sets the left child to NULL
		root->rightChild = NULL; //sets the right child to NULL
		//We need some code here to add to linked list
	}
}//end of add node
void bTree::rAdd(Token **token, node *tokNode, int line) //This is the recursive add method
{
	string a = (*token)->getTokenString(); //sets tokenString a
	string b = (tokNode->treeNode).getTokenString(); //sets tokenString b
	if(a.compare(b) < 0) //If string a compared to string b is less than 0, it will traverse the left side
	{
		if(tokNode->leftChild != NULL) //if leftChild is not empty, it will keep going
		{
			rAdd(**token, tokNode->leftChild, line); //This add has the wrong parameters, we need to fix this.
		}
		else //This will add the token to linked list and the tree
			tokNode->leftChild = new node; //creates a new node for the leftChild
			tokNode->leftChild->treeNode = (*token); //sets the node for leftChild to be pointer of token
			tokNode->leftChild->leftChild = NULL; //sets the leftChild of leftChild to Null
			tokNode->leftChild->rightChild = NULL; //sets the rightChild of leftChild to Null
			//We need some code here to add to linked list
	}
	else if(a.compare(b) > 0) //if string a compared to b is greater than 0, then it will traverse the right side
	{
		if(tokNode->rightChild != NULL) //if rightChild is not empty, it will keep going
		{
			rAdd(**token, tokNode->leftChild, line); //This add has the wrong parameters, we need to fix this.
		}
		else //This will add the token to linked list and the tree
			tokNode->rightChild = new node; //creates a new node for the rightChild
			tokNode->rightChild->treeNode = (*token); //sets the node for leftChild to be pointer of token
			tokNode->rightChild->leftChild = NULL; //sets the leftChild of rightChild to Null
			tokNode->rightChild->rightChild = NULL; //sets the rightChild of rightChild to Null
			//We need some code here to add to linked list
	}
	else if(a.compare(b) == 0) //if string a compared to string b = 0, it will add line number to linked list.
	{
		//We need some code here to add to linked list
	}
}//end of recursive add node

void bTree::destroy() //this calls the recursive destroy method to destroy the binary tree.
{
	rDestroy(root); //calls the recursive destroy method
} //end of destroy method

void bTree::rDestroy(node *tokNode) //destroys the tree using post-order traversal
{
	if(tokNode != NULL)
	{
		rDestroy(tokNode->leftChild); //this will destroy the left child.
		rDestroy(tokNode->rightChild); //this will destroy the right child.
		delete*tokNode; //destroys the parent of the left and right child.
	}
} //end of rDestroy method
