//============================================================================
// Name        : hwAssignment2.cpp
// Author      : Klementina Stojanovska
// Version     :
// Copyright   : Your copyright notice
// Description : Tests all of the new methods in DLList
//============================================================================

#include <iostream>
#include "DLList.h"
using namespace std;
using namespace ods;


void testIsPalindrome(){
	cout<<"TESTING ISPALINDROME: "<<endl;
	DLList<int> *d = new DLList<int>();
		d->add(0,1);
		d->add(1,4);
		d->add(2,3);
		d->add(3,4);
		d->add(4,1);
	cout<< "A list contains 1,4,3,4,1 in that order."<<endl;
	cout<< "The test for isPalindrome comes out to be: "
			"" << d->isPalindrome()<<endl;
	cout<<"(A result of 1 means it is a palindrome and "
			"a result of 0 means it is not.)"<<endl;
	delete d;
}

void testRotate(){
	cout<<"TESTING ROTATE: "<<endl;
	DLList<char> l1;
	l1.add(0,'a');
	l1.add(1,'b');
	l1.add(2,'c');
	l1.add(3,'d');
	l1.add(4,'e');

	cout<<"List 1 contains the characters a, b, c,"
			" d, e in that order"<<endl;
	l1.rotate(2);

	string result = "";
	for(int i = 0; i<l1.size(); i++){
		result = result + l1.get(i) + " ";
	}

	cout<<"After the rotate(r) method is called, "
			"with an r of 2, the list is now: "<<endl;
	cout<<result<<endl;
}

void testAbsorb(){
	cout<<"TESTING ABSORB: "<<endl;
	DLList<char> l1;
	DLList<char> l2;
	l1.add(0,'a');
	l1.add(1,'b');
	l1.add(2,'c');
	l2.add(0,'d');
	l2.add(1,'e');
	l2.add(2,'f');
	l2.add(3,'g');

	l1.absorb(l2);
	string result = "";
	for(int i = 0; i< l1.size(); i++){
		result = result + l1.get(i) + " ";
	}

	cout<< "List 1 contains a,b,c. List 2 "
			"contains d,e,f, g" << endl;

	cout<< "After the absorb method is called:"<<endl;
	cout<<"List 1 contains: " << result <<endl;

}

void testDeal(){
	cout<<"TESTING DEAL: "<<endl;
	DLList<char> *l1 = new DLList<char>();
	l1->add(0,'a');
	l1->add(1,'b');
	l1->add(2,'c');
	l1->add(3,'d');
	l1->add(4,'e');
	l1->add(5,'f');
	l1->add(6,'g');

	cout<<"list 1 contains the characters "
			"a, b, c, d, e, f, g."<<endl;

	DLList<char> l2 = l1->deal();

	string resultL2 = "";
	for(int i = 0; i< l2.size(); i++){
		resultL2 = resultL2 + l2.get(i) + " ";

	}

	string resultL1 = "";
	for(int j = 0; j< l1->size(); j++){
		resultL1 = resultL1 + l1->get(j) + " ";
	}
	cout<<"After the deal method is called:"<<endl;
	cout<<"List 1 contains: " << resultL1<< endl;
	cout<<"List 2 contains: " << resultL2<<endl;

	delete l1;

}

int main() {
    testIsPalindrome();
    cout<<endl;
    testRotate();
    cout<<endl;
    testAbsorb();
    cout<<endl;
    testDeal();
	return 0;
}


