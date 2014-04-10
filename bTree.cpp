/*
 *Authors: Aaron Chasse, Jake Borg, Deming Liu
 *CSE 220 - Lab 4
 *04/09/2014
 *
 *Program Description: bTree.cpp
 *Contains the methods needed to implement a Binary Search Tree. Recursive methods to add a new Token
 *to the tree in alphabetic order, print the entire tree in a post-order manner, 
 *and destroy the tree when the tree deconstructor is called. 
 *
 * Created By: Doug Liu
 *
 */

#include "bTree.h"

bTree::bTree() //This is the constructor
{
  root = NULL;
}
bTree::~bTree() //This is the destructor
{
  //Call the destroyTree method which will recursively destroy the binary tree.
  destroyTree();
}
void bTree::addToTree(Token *token, int line)
{
	if(root != NULL)
	{
		if(token != NULL)
		{
		rAddToTree(token, root, line); //This will recursively call rAdd function to add the tree to the right place
		}
	}
	else
	{
		root = token;
		root->setLeftChild(NULL);
		root->setRightChild(NULL);
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

		}
	}
	else if(a.compare(b) > 0)
	{
		if(tokNode->getRightChild() != NULL)
		{
			rAddToTree(token, tokNode->getRightChild(), line);
		}
		else
		{
			tokNode->setRightChild(token);
			tokNode->getRightChild()->setLeftChild(NULL);
			tokNode->getRightChild()->setRightChild(NULL);

		}
	}
	else if(a.compare(b) == 0)
	{
		//add the line to the linked list for the Token that already exists in the tree
		tokNode->setList(line);
		//delete the token since we already have a copy of it in the tree
		delete token;
	}
}

void bTree::destroyTree()
{
	//call recursive method to dismantle the tree
	rDestroyTree(root);
}

void bTree::rDestroyTree(Token *tokNode)
{
	//recursively delete the binary tree
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
	//recursive print the binary tree 'in-order'
	if(tokNode != NULL)
	{
		rPrintTree(tokNode->getLeftChild());
		printf("%s\t\t\t",tokNode->getTokenString().c_str() );
		tokNode->getList().printList();
		cout<<"\n";
		rPrintTree(tokNode->getRightChild());
	}
}

