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
		rAddToTree(token, root, line); //This will recursively call rAdd function to add the tree to the right place
	}
	else
	{
		root = token;
		root->setLeftChild(NULL);
		root->setRightChild(NULL);
		//We need some code here to add to linked list
		root->setList(line);
	}
}
void bTree::rAddToTree(Token *token, Token *tokNode, int line)
{
	string a = token->getTokenString();
	string b = tokNode->getTokenString();
	if(a.compare(b) < 0)
	{
		if(tokNode->getLeftChild() != NULL)
		{
			rAddToTree(token, tokNode->getLeftChild(), line);
		}
		else
		{
			tokNode->setLeftChild(token);
			tokNode->getLeftChild()->setLeftChild(NULL);
			tokNode->getLeftChild()->setRightChild(NULL);
			//We need some code here to add to linked list
			tokNode->setList(line);
		}
	}
	else if(a.compare(b) > 0)
	{
		if(tokNode->getRightChild() != NULL)
		{
			rAddToTree(token, tokNode->getLeftChild(), line);
		}
		else
		{
			tokNode->setRightChild(token);
			tokNode->getRightChild()->setLeftChild(NULL);
			tokNode->getRightChild()->setRightChild(NULL);
			//We need some code here to add to linked list
			tokNode->setList(line);
		}
	}
	else if(a.compare(b) == 0)
	{
		//We need some code here to add to linked list
		tokNode->setList(line);
		delete token;
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

void bTree::printTree() //This is the print method that will print the tree and calls the recursive print method.
{
	rPrintTree(root);
}

void bTree::rPrintTree(Token *tokNode)
{
	if(tokNode != NULL)
	{
		rPrintTree(tokNode->getLeftChild());
		printf("%s/t/t/t",tokNode->getTokenString().c_str() );
		tokNode->getList().printList();
		cout<<"\n"<<endl;
		rPrintTree(tokNode->getRightChild());
	}
}

