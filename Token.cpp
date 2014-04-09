/*
 *Authors: Aaron Chasse, Jake Borg, Deming Liu
 *CSE 220 - Lab 4
 *04/09/2014
 *
 *Program Description: Token.cpp
 *Contains the methods inherent to the Token object needed to get and set the internal data. 
 *When Token deconstructor is called it will call the deleteList method of its LinkedList object
 *to iterate through the list and free the memory.
 *
 *Created by Bryce Holton.
 *
*/


#include "Token.h"

Token::Token()
{
    //Make sure both child pointers are NULL for proper iteration through BST
    leftChild = NULL;
    rightChild = NULL;
}
Token::~Token()
{
    //This will call the deleteList method on the LinkedList object for this instance
    //of the Token. deleteList() will iterate through the LinkedList and delete each object on the heap
    //except for the first one, which will be freed automatically
    //when the Token object itself is freed since memory for it was allocated when Token was instantiated.
    lines.deleteList();
}
void Token::setCode(TokenCode newCode)
{
    this->code = newCode;
}
TokenCode Token::getCode()
{
    return this->code;
}
void Token::setType(LiteralType newType)
{
    this->type = newType;
}
LiteralType Token::getType()
{
    return this->type;
}
void Token::setLiteral(int newInteger)
{
    this->literal.integer = newInteger;
}
int Token::getIntLiteral()
{
    return this->literal.integer;
}
void Token::setLiteral(float newReal)
{
    this->literal.real = newReal;
}
float Token::getRealLiteral()
{
    return this->literal.real;
}
void Token::setLiteral(string newString)
{
    this->literal.stringLiteral = (char*)malloc(sizeof(char) * newString.length() + 1);
    strcpy(this->literal.stringLiteral, newString.c_str());
}
string Token::getStringLiteral()
{
    return string(this->literal.stringLiteral);
}
void Token::setTokenString(string s)
{
    this->tokenString = s;
}
string Token::getTokenString()
{
    return this->tokenString;
}

//Methods for implementing the Binary Search Tree
LinkedList Token::getList()
{
	return this->lines;
}
void Token::setList(int newLine)
{
	//This will call addToList method of lines object to create a new instance of LinkedList.
	lines.addToList(newLine);
}
void Token::setLine(int line)
{
	this->lines.set(line);
}

//These methods are for setting and getting the child nodes of the Token object
Token *Token::getLeftChild()
{
	return this->leftChild;
}
void Token::setLeftChild(Token *newToken)
{
	this->leftChild = newToken;
}
Token *Token::getRightChild()
{
	return this->rightChild;
}
void Token::setRightChild(Token *newToken)
{
	this->rightChild = newToken;
}

