//Klementina Stojanovska
//CSE 274
//Assignment 2

#ifndef DLLIST_H_
#define DLLIST_H_

namespace ods {

template<class T>
class DLList {
protected:
	struct Node {
		T x;
		Node *prev, *next;
	};
	Node dummy;
	int n;
	void remove(Node *w);
	Node* addBefore(Node *w, T x);
	Node* getNode(int i);
public:
	DLList();
	virtual ~DLList();
	int size() {
		return n;
	}
	T get(int i);
	T set(int i, T x);
	virtual void add(int i, T x);
	virtual void add(T x) {
		add(size(), x);
	}
	virtual T remove(int i);
	virtual void clear();
	bool isPalindrome();
	void rotate(int r);
	void absorb(DLList<T> &l2);
	DLList deal();
};

template<class T>
DLList<T>::DLList() {
	dummy.next = &dummy;
	dummy.prev = &dummy;
	n = 0;
}

template<class T>
typename DLList<T>::Node* DLList<T>::addBefore(Node *w, T x) {
	Node *u = new Node;
	u->x = x;
	u->prev = w->prev;
	u->next = w;
	u->next->prev = u;
	u->prev->next = u;
	n++;
	return u;
}

template<class T>
typename DLList<T>::Node* DLList<T>::getNode(int i) {
	Node* p;
	if (i < n / 2) {
		p = dummy.next;
		for (int j = 0; j < i; j++)
			p = p->next;
	} else {
		p = &dummy;
		for (int j = n; j > i; j--)
			p = p->prev;
	}
	return (p);
}

template<class T>
DLList<T>::~DLList() {
	clear();
}

template<class T>
void DLList<T>::clear() {
	Node *u = dummy.next;
	while (u != &dummy) {
		Node *w = u->next;
		delete u;
		u = w;
	}
	n = 0;
}

template<class T>
void DLList<T>::remove(Node *w) {
	w->prev->next = w->next;
	w->next->prev = w->prev;
	delete w;
	n--;
}

template<class T>
T DLList<T>::get(int i) {
	return getNode(i)->x;
}

template<class T>
T DLList<T>::set(int i, T x) {
	Node* u = getNode(i);
	T y = u->x;
	u->x = x;
	return y;
}

template<class T>
void DLList<T>::add(int i, T x) {
	addBefore(getNode(i), x);
}

template<class T>
T DLList<T>::remove(int i) {
	Node *w = getNode(i);
	T x = w->x;
	remove(w);
	return x;
}

template<class T>
bool DLList<T>::isPalindrome() {
	Node *head = dummy.next;
	Node *tail = dummy.prev;

	while (head < tail) {
		if (head->x == tail->x) {
			head = head->next;
			tail = tail->prev;
		} else
			return false;
	}
	return true;
}

template<class T>
void DLList<T>::rotate(int r) {
	for (int i = 0; i < n; i++) {
		int newIndex = (i + r) % n;
		if (newIndex == 0) {
			Node *w = getNode(i);
			dummy.prev->next = dummy.next;
			dummy.next->prev = dummy.prev;
			dummy.prev = w->prev;
			dummy.next = w;
			w->prev = &dummy;
			dummy.prev->next = &dummy;
		}
	}
}

template<class T>
void DLList<T>::absorb(DLList<T> &l2) {
	dummy.prev->next = l2.dummy.next;
	l2.dummy.next->prev = dummy.prev;
	dummy.prev = l2.dummy.prev;
	l2.dummy.prev->next = &(dummy);
	n += l2.size();
	l2.n = 0;
	l2.dummy.next = &(l2.dummy);
	l2.dummy.prev = &(l2.dummy);
}

template<class T>
DLList<T> DLList<T>::deal() {
	DLList<T> l2;
	Node *start = dummy.next;
	int index = 0;
	int length = size();

	while (index < length) {
		if (index % 2 != 0) {
			Node *w = start->next;
			//removes w from list 1
			w->prev->next = w->next;
			w->next->prev = w->prev;
			n--;
			//adds w to list 2
			l2.dummy.prev->next = w;
			w->prev = l2.dummy.prev;
			w->next = &(l2.dummy);
			l2.dummy.prev = w;
			l2.n++;
			//sets a new start;
			start = start->next;
		}
		index++;
	}
	return l2;
}

} /* namespace ods */

#endif /* DLLIST_H_ */

