//============================================================================
// Name        : Assignment5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ChainedHashTable.h"
#include "LinearHashTable.h"
#include "RedBlackTree.h"
#include "BinarySearchTree.h"
#include "DataStructureTester.h"
using namespace std;
using namespace ods;

void testForChainedHash(int numElements) {
	cout << "FOR CHAINED HASH TABLE: " << endl;
	DataStructureTester<ChainedHashTable<int> > test;

	double avgSeqAdd = 0, avgSeqFind = 0, avgSeqRemove = 0;
	double avgRandAdd = 0, avgRandFind = 0, avgRandRemove = 0;

	int repeat = 20;
	for (int i = 0; i < repeat; i++) {
		avgSeqAdd += test.doSequentialAdd(0, numElements, 2);
		avgSeqFind += test.doSequentialFind(0, numElements, 2);
		avgSeqRemove += test.doSequentialRemove(0, numElements, 2);
		avgRandAdd += test.doRandomAdd(numElements);
		avgRandFind += test.doRandomFind(numElements);
		avgRandRemove += test.doRandomRemove(numElements);
	}

	cout << "The average time it takes (in milliseconds) to do " << numElements
			<< " sequential adds is: " << avgSeqAdd / repeat << endl;
	cout << "The average time it takes (in milliseconds) to do " << numElements
			<< " sequential finds is: " << avgSeqFind / repeat << endl;
	cout << "The average time it takes (in milliseconds) to do " << numElements
			<< " sequential removes is: " << avgSeqRemove / repeat << endl;
	cout << "The average time it takes (in milliseconds) to do " << numElements
			<< " random adds is: " << avgRandAdd / repeat << endl;
	cout << "The average time it takes (in milliseconds) to do " << numElements
			<< " random finds is: " << avgRandFind / repeat << endl;
	cout << "The average time it takes (in milliseconds) to do " << numElements
			<< " random removes is: " << avgRandRemove / repeat << endl;
}

void testForLinearHash(int numElements) {
	cout << "FOR LINEAR HASH TABLE: " << endl;
	DataStructureTester<LinearHashTable<int> > test;

	double avgSeqAdd = 0, avgSeqFind = 0, avgSeqRemove = 0;
	double avgRandAdd = 0, avgRandFind = 0, avgRandRemove = 0;

	int repeat = 20;
	for (int i = 0; i < repeat; i++) {
		avgSeqAdd += test.doSequentialAdd(0, numElements, 2);
		avgSeqFind += test.doSequentialFind(0, numElements, 2);
		avgSeqRemove += test.doSequentialRemove(0, numElements, 2);
		avgRandAdd += test.doRandomAdd(numElements);
		avgRandFind += test.doRandomFind(numElements);
		avgRandRemove += test.doRandomRemove(numElements);
	}

	cout << "The average time it takes (in milliseconds) to do " << numElements
			<< " sequential adds is: " << avgSeqAdd / repeat << endl;
	cout << "The average time it takes (in milliseconds) to do " << numElements
			<< " sequential finds is: " << avgSeqFind / repeat << endl;
	cout << "The average time it takes (in milliseconds) to do " << numElements
			<< " sequential removes is: " << avgSeqRemove / repeat << endl;
	cout << "The average time it takes (in milliseconds) to do " << numElements
			<< " random adds is: " << avgRandAdd / repeat << endl;
	cout << "The average time it takes (in milliseconds) to do " << numElements
			<< " random finds is: " << avgRandFind / repeat << endl;
	cout << "The average time it takes (in milliseconds) to do " << numElements
			<< " random removes is: " << avgRandRemove / repeat << endl;
}

void testForBST(int numElements) {
	cout << "FOR BINARY SEARCH TREE: " << endl;
	DataStructureTester<BinarySearchTree<BSTNode1<int>, int> > test;

	double avgSeqAdd = 0, avgSeqFind = 0, avgSeqRemove = 0;
	double avgRandAdd = 0, avgRandFind = 0, avgRandRemove = 0;

	int repeat = 20;
	for (int i = 0; i < repeat; i++) {
		avgSeqAdd += test.doSequentialAdd(0, numElements, 2);
		avgSeqFind += test.doSequentialFind(0, numElements, 2);
		avgSeqRemove += test.doSequentialRemove(0, numElements, 2);
		avgRandAdd += test.doRandomAdd(numElements);
		avgRandFind += test.doRandomFind(numElements);
		avgRandRemove += test.doRandomRemove(numElements);
	}

	cout << "The average time it takes (in milliseconds) to do " << numElements
			<< " sequential adds is: " << avgSeqAdd / repeat << endl;
	cout << "The average time it takes (in milliseconds) to do " << numElements
			<< " sequential finds is: " << avgSeqFind / repeat << endl;
	cout << "The average time it takes (in milliseconds) to do " << numElements
			<< " sequential removes is: " << avgSeqRemove / repeat << endl;
	cout << "The average time it takes (in milliseconds) to do " << numElements
			<< " random adds is: " << avgRandAdd / repeat << endl;
	cout << "The average time it takes (in milliseconds) to do " << numElements
			<< " random finds is: " << avgRandFind / repeat << endl;
	cout << "The average time it takes (in milliseconds) to do " << numElements
			<< " random removes is: " << avgRandRemove / repeat << endl;
}

void testForRedBlack(int numElements) {
	cout << "FOR RED-BLACK TREE: " << endl;
	DataStructureTester<RedBlackTree<RedBlackNode1<int>, int> > test;

	double avgSeqAdd = 0, avgSeqFind = 0, avgSeqRemove = 0;
	double avgRandAdd = 0, avgRandFind = 0, avgRandRemove = 0;

	int repeat = 20;
	for (int i = 0; i < repeat; i++) {
		avgSeqAdd += test.doSequentialAdd(0, numElements, 2);
		avgSeqFind += test.doSequentialFind(0, numElements, 2);
		avgSeqRemove += test.doSequentialRemove(0, numElements, 2);
		avgRandAdd += test.doRandomAdd(numElements);
		avgRandFind += test.doRandomFind(numElements);
		avgRandRemove += test.doRandomRemove(numElements);
	}

	cout << "The average time it takes (in milliseconds) to do " << numElements
			<< " sequential adds is: " << avgSeqAdd / repeat << endl;
	cout << "The average time it takes (in milliseconds) to do " << numElements
			<< " sequential finds is: " << avgSeqFind / repeat << endl;
	cout << "The average time it takes (in milliseconds) to do " << numElements
			<< " sequential removes is: " << avgSeqRemove / repeat << endl;
	cout << "The average time it takes (in milliseconds) to do " << numElements
			<< " random adds is: " << avgRandAdd / repeat << endl;
	cout << "The average time it takes (in milliseconds) to do " << numElements
			<< " random finds is: " << avgRandFind / repeat << endl;
	cout << "The average time it takes (in milliseconds) to do " << numElements
			<< " random removes is: " << avgRandRemove / repeat << endl;
}

int main() {
	int numElements = 50000;
	testForChainedHash(numElements);
	cout << "" << endl;
	testForLinearHash(numElements);
	cout << "" << endl;
	testForBST(numElements);
	cout << "" << endl;
	testForRedBlack(numElements);

	return 0;
}
