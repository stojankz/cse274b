
/*
 * BinaryTree.h
 *
 *  Created on: 2011-11-28
 *      Author: morin
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include <cstdlib>
#include "ArrayDeque.h"

namespace ods {

template<class N>
class BTNode {
public:
	N *left;
	N *right;
	N *parent;
	BTNode() {
		left = right = parent = NULL;
	}
};


template<class Node>
class BinaryTree {
protected:
	Node *r;    // root node
	Node *nil;  // null-like node
	virtual int size(Node *u);
	virtual int height(Node *u);
	virtual void traverse(Node *u);
public:
	virtual ~BinaryTree();
	BinaryTree();
	BinaryTree(Node *nil);
	virtual void clear();
	virtual int depth(Node *u);
	virtual int size();
	virtual int size2();
	virtual int height();
	virtual void traverse();
	virtual void traverse2();
	virtual void bfTraverse();
	virtual int height2(Node *u);
	virtual int height2();
	virtual bool isBalanced();
	virtual bool isBalanced(Node *u);
	//virtual int isBalanced(Node *u);
	virtual int subtreeSize(Node *u);
};

class BTNode1 : public BTNode<BTNode1> { };


template<class Node>
BinaryTree<Node>::~BinaryTree() {
	clear();
}

template<class Node>
void BinaryTree<Node>::clear() {
	Node *u = r, *prev = nil, *next;
	while (u != nil) {
		if (prev == u->parent) {
			if (u->left != nil) next = u->left;
			else if (u->right != nil) next = u->right;
			else next = u->parent;
		} else if (prev == u->left) {
			if (u->right != nil) next = u->right;
			else next = u->parent;
		} else {
			next = u->parent;
		}
		prev = u;
		if (next == u->parent)
			delete u;
		u = next;
	}
	r = nil;
}

template<class Node>
BinaryTree<Node>::BinaryTree(Node *nil) {
	this->nil = nil;
	r = nil;
}

template<class Node>
BinaryTree<Node>::BinaryTree() {
	nil = NULL;
	r = nil;
}


template<class Node>
int BinaryTree<Node>::depth(Node *u) {
	int d = 0;
	while (u != r) {
		u = u->parent;
		d++;
	}
	return d;
}

template<class Node>
int BinaryTree<Node>::size() {
	return size(r);
}

template<class Node>
int BinaryTree<Node>::size(Node *u) {
	if (u == nil) return 0;
	return 1 + size(u->left) + size(u->right);
}

template<class Node>
int BinaryTree<Node>::size2() {
		Node *u = r, *prev = nil, *next;
		int n = 0;
		while (u != nil) {
			if (prev == u->parent) {
				n++;
				if (u->left != nil) next = u->left;
				else if (u->right != nil) next = u->right;
				else next = u->parent;
			} else if (prev == u->left) {
				if (u->right != nil) next = u->right;
				else next = u->parent;
			} else {
				next = u->parent;
			}
			prev = u;
			u = next;
		}
		return n;
	}


template<class Node>
int BinaryTree<Node>::height() {
	return height(r);
}

template<class Node>
int BinaryTree<Node>::height(Node *u) {
	if (u == nil) return -1;
	return 1 + max(height(u->left), height(u->right));
}

template<class Node>
void BinaryTree<Node>::traverse() {
	traverse(r);
}

template<class Node>
void BinaryTree<Node>::traverse(Node *u) {
		if (u == nil) return;
		traverse(u->left);
		traverse(u->right);
}

template<class Node>
void BinaryTree<Node>::traverse2() {
	Node *u = r, *prev = nil, *next;
	while (u != nil) {
		if (prev == u->parent) {
			if (u->left != nil) next = u->left;
			else if (u->right != nil) next = u->right;
			else next = u->parent;
		} else if (prev == u->left) {
			if (u->right != nil) next = u->right;
			else next = u->parent;
		} else {
			next = u->parent;
		}
		prev = u;
		u = next;
	}
}

//This method goes through the tree
//and calculates the height of the tree
//starting at Node u. Uses an iterative
//approach rather than recursive.
template<class Node>
int BinaryTree<Node>::height2(Node* u){
	Node *prev = u->parent, *next;
	Node *parentNode = u->parent;
	int height = 0;
	int maxHeight =0;
	while(u != parentNode){
		if(prev == u->parent){
			if(u->left != nil) next = u->left;
			else if(u->right != nil) next = u->right;
			else next = u->parent;
			if(next != u->parent) height++;
		}else if(prev == u->left){
			if(u->right != nil) next = u->right;
			else next = u->parent;
			if(next != u->parent) height++;
		}else{
			next = u->parent;
		}
		if(next == u->parent){
			if(height> maxHeight){
				maxHeight = height;
			}
			height--;
		}
		prev = u;
		u = next;
	}
	return maxHeight;
}

//calls the height2 method for
// the root node, r.
template<class Node>
int BinaryTree<Node>::height2(){
	return height2(r);
}

//calls the isBalanced(Node *u) method
//for the root node, r.
template<class Node>
bool BinaryTree<Node>::isBalanced(){
//	if(isBalanced(r)<=1){
//		return true;
//	}
//	return false;
	return isBalanced(r);
}

//checks the size of the left subtree and
//the right subtree to see if the tree is balanced
template<class Node>
bool BinaryTree<Node>::isBalanced(Node *u){
		int sizeLeft = subtreeSize(r->left);
		int sizeRight = subtreeSize(r->right);
		if(abs(sizeLeft-sizeRight) <=1 ){
			return true;
		}
		return false;
//	if(u == nil || u->right == nil || u->left== nil) return 0;
//	return abs((1+isBalanced(u->left->left)+ isBalanced(u->left->right))- (1+ isBalanced(u->right->left) + isBalanced(u->right->right)));
}

template<class Node>
void BinaryTree<Node>::bfTraverse() {
	ArrayDeque<Node*> q;
	if (r != nil) q.add(q.size(),r);
	while (q.size() > 0) {
		Node *u = q.remove(q.size()-1);
		if (u->left != nil) q.add(q.size(),u->left);
		if (u->right != nil) q.add(q.size(),u->right);
	}
}

template<class Node>
int BinaryTree<Node>:: subtreeSize(Node *u){
	if (u == nil) return 0;
		return 1 + subtreeSize(u->left) + subtreeSize(u->right);
}



} /* namespace ods */
#endif /* BINARYTREE_H_ */
