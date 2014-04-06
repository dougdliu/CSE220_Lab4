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
void bTree::add(Token **token, int line)
{
	if(root != NULL)
	{
		add(*token, root, line); //This add has the wrong parameters, we need to fix this.
	}
	else
	{
		root = new node;
		root->treeNode = (*token);
		root->leftChild = NULL;
		root->rightChild = NULL;
		//We need some code here to add to linked list
	}
}
void bTree::add(Token **token, node *tokNode, int line)
{
	string a = (*token)->getTokenString();
	string b = (tokNode->treeNode).getTokenString();
	if(a.compare(b) < 0)
	{
		if(tokNode->leftChild != NULL)
		{
			add(**token, tokNode->leftChild, line); //This add has the wrong parameters, we need to fix this.
		}
		else
			tokNode->leftChild = new node;
			tokNode->leftChild->treeNode = (*token);
			tokNode->leftChild->leftChild = NULL;
			tokNode->leftChild->rightChild = NULL;
			//We need some code here to add to linked list
	}
	else if(a.compare(b) > 0)
	{
		if(tokNode->rightChild != NULL)
		{
			add(**token, tokNode->leftChild, line); //This add has the wrong parameters, we need to fix this.
		}
		else
			tokNode->rightChild = new node;
			tokNode->rightChild->treeNode = (*token);
			tokNode->rightChild->leftChild = NULL;
			tokNode->rightChild->rightChild = NULL;
			//We need some code here to add to linked list
	}
	else if(a.compare(b) == 0)
	{
		//We need some code here to add to linked list
	}
}

void bTree::destroy()
{
	destroy(root);
}

void bTree::destroy(node *tokNode)
{
	if(tokNode != NULL)
	{
		destroy(tokNode->leftChild);
		destroy(tokNode->rightChild);
		delete*tokNode;
	}
}
