//============================================================================
// Name        : Assignment6.cpp
// Author      : Klementina Stojanovska
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "BinaryHeap.h"
using namespace ods;
using namespace std;

void addValuesInHeap(BinaryHeap<int> &h){
	cout<<"Adding 3, 17, 92, 44, 2, and 13 to the binary heap"<<endl;
	h.add(3);
	h.add(17);
	h.add(92);
	h.add(44);
	h.add(2);
	h.add(13);

}

void getSize(BinaryHeap<int> &h){
	int size = h.size();
	cout<<"The size of the heap is: " << size<< endl;
}

void removeElement(BinaryHeap<int> & h, int index){
	cout<< "Removing the number a position " << index << " from the heap." <<endl;
	int x = h.remove(index);
	cout<< x << " was successfully removed."<<endl;
	int size = h.size();
	cout<<"The size of the heap is now: "<<size<<endl;
}

int main() {
	BinaryHeap<int> heap;
	addValuesInHeap(heap);
	getSize(heap);
	removeElement(heap, 2);
	removeElement(heap,2);
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
