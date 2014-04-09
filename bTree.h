/*
 *Authors: Aaron Chasse, Jake Borg, Deming Liu
 *CSE 220 - Lab 4
 *04/09/2014
 *
 *Program Description: bTree.h
 *Header file contains the bTree class definition.
 *
 * Created by: Doug Liu
 *
*/

#ifndef Lab4_bTree_H
#define Lab4_bTree_H

#include "Token.h"
#include "common.h"

using namespace std;


class bTree
{

public:
  bTree();
  ~bTree();

  void addToTree(Token *token, int line);
  void destroyTree();
  void printTree(); //method to print and calls rPrint recursively

private:
  void rAddToTree(Token *token, Token *tokNode, int line);
  void rDestroyTree(Token *tokNode);
  void rPrintTree(Token *tokNode);

	Token *root;
};

#endif

