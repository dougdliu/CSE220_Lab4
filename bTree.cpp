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
  destroyTree();
}
void bTree::addToTree(Token *token, int line)
{
	if(root != NULL)
	{
		rAddToTree(token, root, line); //This add has the wrong parameters, we need to fix this.
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
void bTree::rAddToTree(Token *token, Token *tokNode, int line)
{
	string a = token->getTokenString();
	string b = tokNode->getTokenString();
	if(a.compare(b) < 0)
	{
		if(tokNode->getLeftChild != NULL)
		{
			rAddToTree(token, tokNode->getLeftChild(), line);
		}
		else
		{
			token->setLeftChild(token);
			tokNode->getLeftChild()->setLeftChild(NULL);
			tokNode->getLeftChild()->setRightChild(NULL);
			//We need some code here to add to linked list
			tokNode->lines.addToList(&((token)->lines), line);
		}
	}
	else if(a.compare(b) > 0)
	{
		if(tokNode->getRightChild != NULL)
		{
			rAddToTree(token, tokNode->leftChild, line);
		}
		else
		{
			tokNode->setRightChild(token);
			tokNode->getRightChild()->setLeftChild(NULL);
			tokNode->getRightChild()->setRightChild(NULL);
			//We need some code here to add to linked list
			tokNode->lines.addToList(&((token)->lines), line);
		}
	}
	else if(a.compare(b) == 0)
	{
		//We need some code here to add to linked list
		tokNode->lines.addToList(&((token)->lines), line);
	}
}

void bTree::destroyTree()
{
	rDestroyTree(root);
}

void bTree::rDestroyTree(Token *tokNode)
{
	if(tokNode != NULL)
	{
		rDestroyTree(tokNode->getLeftChild());
		rDestroyTree(tokNode->getRightChild());
		delete tokNode;
	}
}

void bTree::printTree(Token *token) //This is the print method that will print the tree and calls the recursive print method.
{
	rPrintTree(token, root);
}

void bTree::rPrintTree(Token *token, Token *tokNode)
{
	if(tokNode != NULL)
	{
		rPrintTree(token ,tokNode->getLeftChild());
		printf("%s",tokNode->getTokenString().c_str);
		tokNode->lines.printList(&((token)->lines));
		cout<<"\n"<<endl;
		rPrintTree(token, tokNode->getRightChild());
	}
}

