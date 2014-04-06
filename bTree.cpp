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
void bTree::add(Token *token, int line)
{
	if(root != NULL)
	{
		rAdd(token, root, line); //This add has the wrong parameters, we need to fix this.
	}
	else
	{
		root = token;
		root->setLeftChild(NULL);
		root->setRightChild(NULL);
		//We need some code here to add to linked list
		root->lines.addToList(&((token)->lines), line);
	}
}
void bTree::rAdd(Token *token, Token *tokNode, int line)
{
	string a = token->getTokenString();
	string b = tokNode->getTokenString();
	if(a.compare(b) < 0)
	{
		if(tokNode->getLeftChild != NULL)
		{
			rAdd(token, tokNode->getLeftChild(), line);
		}
		else
			token->setLeftChild(token);
			tokNode->getLeftChild()->setLeftChild(NULL);
			tokNode->getLeftChild()->setRightChild(NULL);
			//We need some code here to add to linked list
			tokNode->lines.addToList(&((token)->lines), line);
	}
	else if(a.compare(b) > 0)
	{
		if(tokNode->getRightChild != NULL)
		{
			rAdd(token, tokNode->leftChild, line);
		}
		else
			tokNode->setRightChild(token);
			tokNode->getRightChild()->setLeftChild(NULL);
			tokNode->getRightChild()->setRightChild(NULL);
			//We need some code here to add to linked list
			tokNode->lines.addToList(&((token)->lines), line);
	}
	else if(a.compare(b) == 0)
	{
		//We need some code here to add to linked list
		tokNode->lines.addToList(&((token)->lines), line);
	}
}

void bTree::destroy()
{
	rDestroy(root);
}

void bTree::rDestroy(Token *tokNode)
{
	if(tokNode != NULL)
	{
		rDestroy(tokNode->getLeftChild());
		rDestroy(tokNode->getRightChild());
		delete tokNode;
	}
}
