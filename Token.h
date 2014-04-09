/*
 *Authors: Aaron Chasse, Jake Borg, Deming Liu
 *CSE 220 - Lab 4
 *04/09/2014
 *
 *Program Description: Token.h
 *Header file contains the Token class definition.
 *
 *Created by Bryce Holton.
 *
*/


#ifndef __Lab4__Token__
#define __Lab4__Token__

#include <iostream>
#include <stdlib.h>
#include "common.h"
#include "LinkedList.h"

using namespace std;

/**************
 this is a valid Pascal token.  A token must have a literal type,
 a literal value, and a token code.
 ***************/
class Token
{
private:
    TokenCode code;
    LiteralType type;
    union
    {
        int integer;
        float real;
        char *stringLiteral;
    }
    literal;
    string tokenString;
    //Pointers to the Token's left and right child nodes
    Token *leftChild;
    Token *rightChild;
    //LinkedLit object for holding the line number the Token was found on and a pointer to the next
    //LinkedList object in the linked list.
    LinkedList lines;
    
public:
    Token();
    ~Token();
    void setCode(TokenCode newCode);
    TokenCode getCode();
    void setType(LiteralType newType);
    LiteralType getType();
    void setLiteral(int newInteger);
    int getIntLiteral();
    void setLiteral(float newReal);
    float getRealLiteral();
    void setLiteral(string newString);
    string getStringLiteral();
    void setTokenString(string s);
    string getTokenString();
    void setNextToken(Token *newToken);
    Token* getNextToken();
    LinkedList getList();
    void setList(int newLine);
    Token* getLeftChild();
    void setLeftChild(Token *newToken);
    Token* getRightChild();
    void setRightChild(Token *newToken);
    void setLine(int line);
};

#endif /* defined(__Lab4__Token__) */
