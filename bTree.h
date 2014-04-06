/*
 * Created by: Doug Liu
 * Description: This is the header file for the binary tree class.
 *
 */

#include "Token.h"
#include "common.h"

struct node
{
	Token treeNode;
	node *leftChild;
	node *rightChild;
};

class bTree
{
private:
	void add(Token **token, node *tokNode);
	void destroy(node *tokNode);
	node *root;

public:
  bTree();
  ~bTree();
  
  void destroy(node *tokNode);
  void add(Token **token, int line);
};
