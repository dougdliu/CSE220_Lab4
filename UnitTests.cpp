#include "UnitTests.h"

UnitTests::UnitTests() {
	a = new Token();
	b = new Token();
	c = new Token();
	d = new Token();
	a->setTokenString("a");
	b->setTokenString("b");
	c->setTokenString("c");
	d->setTokenString("d");
	tree.addToTree(b,1);
	tree.addToTree(a,0);
	tree.addToTree(d,3);
	tree.addToTree(c,2);
}
/* bTree tests */
bool UnitTests::testAddToTree() {
	if(a != b->getLeftChild()) {
		printf("addToTree left child");
		return 0;
	}
	if(d != b->getRightChild()) {
		printf("addToTree right child");
		return 0;
	}
	if(c != b->getRightChild()->getLeftChild())  {
		printf("addToTree depth of 2");
		return 0;
	}
	return 1;
}
bool UnitTests::testDestroyTree() {
	tree.destroyTree();
	if(a != NULL) { return 0; }
	if(b != NULL) { return 0; }
	if(c != NULL) { return 0; }
	if(d != NULL) { return 0; }
	return 1;
}
