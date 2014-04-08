/*
 * Created by: Doug Liu
 * Description: This is the header file for the binary tree class.
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

