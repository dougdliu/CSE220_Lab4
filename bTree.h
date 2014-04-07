/*
 * Created by: Doug Liu
 * Description: This is the header file for the binary tree class.
 *
 */

#ifndef Lab4_bTree_H;
#define Lab4_bTree_H;

#include "Token.h"
#include "common.h"

using namespace std;

class bTree
{

public:
  	bTree();
  	~bTree();

  	void add(Token *token, int line);
  	void destroy();

private:
	void rAdd(Token *token, Token *tokNode, int line);
	void rDestroy(Token *tokNode);
	Token *root;
};

#endif
