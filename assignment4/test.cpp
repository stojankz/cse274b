//============================================================================
// Name        : Assignment4.cpp
// Author      : Klementina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "BinarySearchTree.h"
#include "BinaryTree.h"
using namespace std;

using namespace ods;

//Method to add values to the BinarySearchTree
void addValuesInTree(BinarySearchTree<BSTNode1<int>,int>& t){
	cout<<"Adding the values 4, 2, 7, 1, 3, 9 to the "
			"BinarySearchTree, in that order." <<endl;
	t.add(4);
	t.add(2);
	t.add(7);
	t.add(1);
	t.add(3);
	t.add(9);
}

//Method that prints the size of the tree
void getSizeOfTree(BinarySearchTree<BSTNode1<int>,int>& t){
	int size = t.size();
	cout<<"The size of the tree is: " <<size<<endl;
}

//Method that tests the height2() method and
//prints the height of the tree
void testHeight2(BinarySearchTree<BSTNode1<int>,int>& t){
	int height = t.height2();
	cout<<"The height of the tree is: "<<height<<endl;
}

//Method that tests the isBalanced() method and
//prints the result
void testIsBalanced(BinarySearchTree<BSTNode1<int>,int>& t){
	bool balanced = t.isBalanced();
	cout<<"Is this tree balanced?(If yes, returns 1, if not returns 0): "<<
			balanced<<endl;
}

//Method that runs the preOrderNumber() method and
//then prints the pre-order numbers for all the
//elements in the tree.
void testPreOrderNumber(BinarySearchTree<BSTNode1<int>,int>& t){
	cout<<"Assigning pre-order numbers to the tree."<<endl;
	t.preOrderNumber();
	cout<<"The pre-order number for 4 is: " << t.getNode(4)->pre_number<<endl;
	cout<<"The pre-order number for 2 is: " << t.getNode(2)->pre_number<<endl;
	cout<<"The pre-order number for 7 is: " << t.getNode(7)->pre_number<<endl;
	cout<<"The pre-order number for 1 is: " << t.getNode(1)->pre_number<<endl;
	cout<<"The pre-order number for 3 is: " << t.getNode(3)->pre_number<<endl;
	cout<<"The pre-order number for 9 is: " << t.getNode(9)->pre_number<<endl;
}

//Method that runs the inOrderNumber() method and
//then prints the in-order numbers for all the
//elements in the tree.
void testInOrderNumber(BinarySearchTree<BSTNode1<int>,int>& t){
	cout<<"Assigning in-order numbers to the tree."<<endl;
	t.inOrderNumber();
	cout<<"The in-order number for 4 is: " << t.getNode(4)->in_number<<endl;
	cout<<"The in-order number for 2 is: " << t.getNode(2)->in_number<<endl;
	cout<<"The in-order number for 7 is: " << t.getNode(7)->in_number<<endl;
	cout<<"The in-order number for 1 is: " << t.getNode(1)->in_number<<endl;
	cout<<"The in-order number for 3 is: " << t.getNode(3)->in_number<<endl;
	cout<<"The in-order number for 9 is: " << t.getNode(9)->in_number<<endl;
}

//Method that runs the postOrderNumber() method and
//then prints the post-order numbers for all the
//elements in the tree.
void testPostOrderNumber(BinarySearchTree<BSTNode1<int>,int>& t){
	cout<<"Assigning post-order numbers to the tree."<<endl;
	t.postOrderNumber();
	cout<<"The post-order number for 4 is: " << t.getNode(4)->post_number<<endl;
	cout<<"The post-order number for 2 is: " << t.getNode(2)->post_number<<endl;
	cout<<"The post-order number for 7 is: " << t.getNode(7)->post_number<<endl;
	cout<<"The post-order number for 1 is: " << t.getNode(1)->post_number<<endl;
	cout<<"The post-order number for 3 is: " << t.getNode(3)->post_number<<endl;
	cout<<"The post-order number for 9 is: " << t.getNode(9)->post_number<<endl;
}

//Method that tests the getLE(i) method and then prints
//all the values that are less than or equal to i.
void testGetLE(BinarySearchTree<BSTNode1<int>,int>& t, int i){
	cout<<"The list of numbers less than or equal to "<<i<< " are: "<<endl;
	DLList<int> list = t.getLE(i);
	for(int i = 0; i< list.size(); i++){
		cout<< list.get(i) << " ";
	}
	cout<<""<<endl;
}

//The main method calls all of the methods.
int main() {
	BinarySearchTree<BSTNode1<int>, int > tree;
	addValuesInTree(tree);
	getSizeOfTree(tree);
	testHeight2(tree);
	testIsBalanced(tree);
	testPreOrderNumber(tree);
	cout<<""<<endl;
	testInOrderNumber(tree);
	cout<<""<<endl;
	testPostOrderNumber(tree);
	cout<<""<<endl;
	testGetLE(tree,9);
	testGetLE(tree,4);
	testGetLE(tree,2);
	return 0;
}


