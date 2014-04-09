#include "UnitTests.h"

UnitTests::UnitTests() {
	/* bTree stuff */
	a = new Token();
	b = new Token();
	c = new Token();
	d = new Token();
	a->setTokenString("a");
	b->setTokenString("b");
	c->setTokenString("c");
	d->setTokenString("d");
}
UnitTests::~UnitTests() {}
/* bTree tests */
bool UnitTests::testAddToTree() {
	tree.addToTree(b,1);
	tree.addToTree(a,0);
	tree.addToTree(d,3);
	tree.addToTree(c,2);
	if(a != b->getLeftChild()) {
		printf("addToTree left child\n");
		return 0;
	}
	if(d != b->getRightChild()) {
		printf("addToTree right child\n");
		return 0;
	}
	if(c != b->getRightChild()->getLeftChild())  {
		printf("addToTree depth of 2\n");
		return 0;
	}
	return 1;
}
bool UnitTests::testDestroyTree() {
	tree.destroyTree();
	if(a != NULL) { printf("a not destroyed\n"); return 0; }
	if(b != NULL) { printf("b not destroyed\n"); return 0; }
	if(c != NULL) { printf("c not destroyed\n"); return 0; }
	if(d != NULL) { printf("d not destroyed\n"); return 0; }
	return 1;
}
/* LinkedList tests */
bool UnitTests::testAddToList() {
	lines.addToList(1);
	lines.addToList(1);
	lines.addToList(2);
	lines.addToList(3);
	if(lines.getNext()->getLine() != 1) { printf("depth 0 not set\n"); return 0; }
	if(lines.getNext()->getNext()->getLine() != 1) { printf("depth 1 not set\n"); return 0; }
	if(lines.getNext()->getNext()->getNext()->getLine() != 2) { printf("depth 2 not set\n"); return 0; }
	if(lines.getNext()->getNext()->getNext()->getNext()->getLine() != 3) { printf("depth 3 not set\n"); return 0; }
	return 1;
}
bool UnitTests::testDeleteList() {
	if(lines.getLine() != NULL) { printf("delete list not working"); return 0;}
	return 1; //? How to test inner nodes?
}
