/*
 * BinarySearchTree.h
 *
 *  Created on: Oct 31, 2014
 *      Author: Klementina
 */

/*
 * BinarySearchTree.h
 *
 *  Created on: 2011-11-28
 *      Author: morin
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include <climits>
#include <cmath>
#include "BinaryTree.h"
#include "utils.h"
#include "DLList.h"

using namespace std;
namespace ods {

template<class Node, class T>
class BSTNode : public BTNode<Node> {
public:
	T x;
	int pre_number;
	int post_number;
	int in_number;
};

/**
 * A binary search tree class.  The Node parameter should be a subclass
 * of BSTNode<T> (or match it's interface)
 */
template<class Node, class T>
class BinarySearchTree : public BinaryTree<Node> {
protected:
	using BinaryTree<Node>::r;
	using BinaryTree<Node>::nil;
	int n;
	int preCount;
	int inCount;
	int postCount;
	T null;
	virtual Node *findLast(T x);
	virtual bool addChild(Node *p, Node *u);
	virtual void splice(Node *u);
	virtual void remove(Node *u);
	virtual void rotateRight(Node *u);
	virtual void rotateLeft(Node *u);
	virtual bool add(Node *u);
	virtual void preOrderNumber(Node *u);
	virtual void inOrderNumber(Node *u);
	virtual void postOrderNumber(Node *u);
public:
	BinarySearchTree();
	BinarySearchTree(T null);
	virtual ~BinarySearchTree();
	virtual bool add(T x);
	virtual bool remove(T x);
	virtual T find(T x);
	virtual T findEQ(T x);
	virtual int size();
	virtual void clear();
	virtual DLList<T> getLE(T x);
	//virtual void getLE(T x);
	virtual Node* getNode(T x);
	virtual void preOrderNumber();
	virtual void inOrderNumber();
	virtual void postOrderNumber();
};

template<class T>
class BSTNode1 : public BSTNode<BSTNode1<T>, T> { };

template<class T>
class BinarySearchTree1 : public BinarySearchTree<BSTNode1<T>, T> {
public:
	BinarySearchTree1();
};


/*
 * FIXME: Why doesn't this work?
template<class Node>
BinarySearchTree<Node,int>::BinarySearchTree()  {
	this->null = INT_MIN;
	n = 0;
}
*/

template<class Node, class T>
BinarySearchTree<Node,T>::BinarySearchTree() {
	this->null = (T)NULL;  // won't work for non-primitive types
	n = 0;
	preCount = 1;
	inCount = 1;
	postCount = 1;
}


template<class Node, class T>
BinarySearchTree<Node,T>::BinarySearchTree(T null) {
	this->null = null;
	n = 0;
	preCount = 0;
	inCount = 0;
	postCount = 0;
}

template<class Node, class T>
Node* BinarySearchTree<Node,T>::findLast(T x) {
	Node *w = r, *prev = nil;
	while (w != nil) {
		prev = w;
		int comp = compare(x, w->x);
		if (comp < 0) {
			w = w->left;
		} else if (comp > 0) {
			w = w->right;
		} else {
			return w;
		}
	}
	return prev;
}

template<class Node, class T>
T BinarySearchTree<Node,T>::findEQ(T x) {
	Node *w = r;
	while (w != nil) {
		int comp = compare(x, w->x);
		if (comp < 0) {
			w = w->left;
		} else if (comp > 0) {
			w = w->right;
		} else {
			return w->x;
		}
	}
	return null;
}

template<class Node, class T>
T BinarySearchTree<Node,T>::find(T x) {
	Node *w = r, *z = nil;
	while (w != nil) {
		int comp = compare(x, w->x);
		if (comp < 0) {
			z = w;
			w = w->left;
		} else if (comp > 0) {
			w = w->right;
		} else {
			return w->x;
		}
	}
	return z == nil ? null : z->x;
}

template<class Node, class T>
BinarySearchTree<Node,T>::~BinarySearchTree() {
	// nothing to do - BinaryTree destructor does cleanup
}

template<class Node, class T>
bool BinarySearchTree<Node, T>::addChild(Node *p, Node *u) {
		if (p == nil) {
			r = u;              // inserting into empty tree
		} else {
			int comp = compare(u->x, p->x);
			if (comp < 0) {
				p->left = u;
			} else if (comp > 0) {
				p->right = u;
			} else {
				return false;   // u.x is already in the tree
			}
			u->parent = p;
		}
		n++;
		return true;
	}

template<class Node, class T>
bool BinarySearchTree<Node, T>::add(T x) {
	Node *p = findLast(x);
	Node *u = new Node;
	u->x = x;
	return addChild(p, u);
}

template<class Node, class T>
bool BinarySearchTree<Node, T>::add(Node *u) {
	Node *p = findLast(u->x);
	return addChild(p, u);
}

template<class Node, class T>
void BinarySearchTree<Node, T>::splice(Node *u) {
	Node *s, *p;
	if (u->left != nil) {
		s = u->left;
	} else {
		s = u->right;
	}
	if (u == r) {
		r = s;
		p = nil;
	} else {
		p = u->parent;
		if (p->left == u) {
			p->left = s;
		} else {
			p->right = s;
		}
	}
	if (s != nil) {
		s->parent = p;
	}
	n--;
}

template<class Node, class T>
void BinarySearchTree<Node, T>::remove(Node *u) {
	if (u->left == nil || u->right == nil) {
		splice(u);
		delete u;
	} else {
		Node *w = u->right;
		while (w->left != nil)
			w = w->left;
		u->x = w->x;
		splice(w);
		delete w;
	}
}

template<class Node, class T>
bool BinarySearchTree<Node, T>::remove(T x) {
	Node *u = findLast(x);
	if (u != nil && compare(x, u->x) == 0) {
		remove(u);
		return true;
	}
	return false;
}

template<class Node, class T> inline
int BinarySearchTree<Node, T>::size() {
	return n;
}

template<class Node, class T> inline
void BinarySearchTree<Node, T>::clear() {
	BinaryTree<Node>::clear();
	n = 0;
}

template<class Node, class T>
void BinarySearchTree<Node, T>::rotateLeft(Node *u) {
	Node *w = u->right;
	w->parent = u->parent;
	if (w->parent != nil) {
		if (w->parent->left == u) {
			w->parent->left = w;
		} else {
			w->parent->right = w;
		}
	}
	u->right = w->left;
	if (u->right != nil) {
		u->right->parent = u;
	}
	u->parent = w;
	w->left = u;
	if (u == r) { r = w; r->parent = nil; }
}

template<class Node, class T>
void BinarySearchTree<Node, T>::rotateRight(Node *u) {
	Node *w = u->left;
	w->parent = u->parent;
	if (w->parent != nil) {
		if (w->parent->left == u) {
			w->parent->left = w;
		} else {
			w->parent->right = w;
		}
	}
	u->left = w->right;
	if (u->left != nil) {
		u->left->parent = u;
	}
	u->parent = w;
	w->right = u;
	if (u == r) { r = w; r->parent = nil; }
}



/*
template<class T>
BinarySearchTree1<T*>::BinarySearchTree1() : BinarySearchTree<BSTNode1<T*>, T*>(NULL) {
}
*/

template<class T>
BinarySearchTree1<T>::BinarySearchTree1()  {
}

//This method finds the node that contains
//the element x that you are looking for
//and returns that node.
template<class Node, class T>
Node* BinarySearchTree<Node,T>:: getNode(T x){
	Node *w = r, *z = nil;
		while (w != nil) {
			int comp = compare(x, w->x);
			if (comp < 0) {
				z = w;
				w = w->left;
			} else if (comp > 0) {
				w = w->right;
			} else {
				return w;
			}
		}
		return z == nil ? nil : z;
}

//Calls the preOrderNumber(Node *u) method,
//calling it for the root node, r.
template<class Node, class T>
void BinarySearchTree<Node,T >:: preOrderNumber(){
	preOrderNumber(r);

}
//This traverses the tree at a given node and
//assigns each node it's pre-order number.
template<class Node, class T>
void BinarySearchTree<Node,T>:: preOrderNumber(Node *u){
	u->pre_number = preCount;
	preCount++;
	if(u->left != nil){
		preOrderNumber(u->left);
	}
	if(u->right != nil){
		preOrderNumber(u->right);
	}
}

//Calls the inOrderNumber(Node *u) method, calling
//it for the root node, r.
template<class Node, class T>
void BinarySearchTree<Node,T>:: inOrderNumber(){
	inOrderNumber(r);
}

//this traverses the tree at a given node and
//assigns each node its in-order number
template<class Node, class T>
void BinarySearchTree<Node, T>:: inOrderNumber(Node *u){
	if(u->left != nil){
		inOrderNumber(u->left);
	}
	u->in_number = inCount;
	inCount++;
	if(u->right != nil){
		inOrderNumber(u->right);
	}
}

//Calls the postOrderNumber(Node *u) method, calling
//it for the root node, r.
template<class Node, class T>
void BinarySearchTree<Node, T>:: postOrderNumber(){
	postOrderNumber(r);
}

//this traverses through the tree at a given node and
//assigns each node it's post-order number
template<class Node, class T>
void BinarySearchTree<Node, T>:: postOrderNumber(Node *u){
	if(u->left != nil){
		postOrderNumber(u->left);
	}
	if(u->right != nil){
		postOrderNumber(u->right);
	}
	u->post_number = postCount;
	postCount++;
}

//This goes through the tree and checks whether x for
//the node is less than or equal to the parameter x.
//If it is, checks to see that the element is not
//already in the DLList, then adds it to the DLList.
//loop breaks when it gets to nodes that have
//values that are greater than x.
template<class Node, class T>
DLList<T> BinarySearchTree<Node, T>:: getLE(T x){
	DLList<T> list;
	Node *u = r, *prev = nil, *next;
	while (u != nil) {
		if (prev == u->parent) {
			if (u->left != nil){
				next = u->left;
			}
			else if (u->right != nil){
				next = u->right;
			}
			else next = u->parent;
			if(u->x <= x && list.contains(u->x) == false)
				list.add(u->x);
			if(u->x > x && next->x > x)
				break;
		} else if (prev == u->left) {
			if (u->right != nil)next = u->right;
			else next = u->parent;
			if(u->x <= x && list.contains(u->x) == false)
				list.add(u->x);
			if(u->x >x && next->x > x)
				break;
		} else {
			next = u->parent;
			if(u->x <= x && list.contains(u->x) == false)
				list.add(u->x);
			if(u->x > x && next->x > x)
				break;
		}
		prev = u;
		u = next;
	}
	return list;
}

} /* namespace ods */
#endif /* BINARYSEARCHTREE_H_ */

