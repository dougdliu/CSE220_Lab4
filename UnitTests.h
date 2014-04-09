/*





*/

#ifndef _Lab4_UnitTests
#define _Lab4_UnitTests

#include <iostream>
#include "common.h"
#include "Print.h"
#include "Scanner.h"
#include "Token.h"
#include "bTree.h"
#include "LinkedList.h"

using namespace std;

class UnitTests {
	public: 
		UnitTests();
		~UnitTests();
		/* Scanner tests */
		bool testGetSourceLine();
		bool testGetChar();
		bool testSkipBlanks();
		bool testSkipComment();
		bool testGetWord();
		// TODO the rest of the methods

		/* bTree tests */
		bool testAddToTree();
		bool testDestroyTree();
	private:
		bTree tree;
		Token *a;
		Token *b;
		Token *c;
		Token *d;
};

#endif
