/*
 * Created by: Doug Liu
 * Description: This is the header file for the binary tree class.
 *
 */

#include "Token.h"
#include "common.h"

class bTree
{
private:


public:
  bTree();
  ~bTree();
  
  void destroy(node *tokNode);
  void add(Token *token, int line);
};
