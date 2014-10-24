//============================================================================
// Name        : Homework3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ChainedHashTable.h"
#include "LinearHashTable.h"
using namespace std;
using namespace ods;

void checkChainedHash(){
  ChainedHashTable<int> t1;
  cout<<"We will add 30 random numbers between 0 and 10, to the Hash Table: " <<endl;

  int random;
  for(int i = 0; i< 30; i++){
    random = rand()%100;
    cout<<"ADDING THE NUMBER: "<<random<<". does it get added?"<<endl;
    cout<<"(If the element already exists in the table, it does "
        "not get added and returns 0. If it gets added, returns 1.)"<<endl;
    cout<< t1.add(random)<<endl;
  }

  cout<<""<<endl;
  cout<<"Test for the size() method: "<<endl;
  cout<<"What is the size of the Chained Hash Table?"<<endl;
  cout<< t1.size()<<endl;

  cout<<""<<endl;
  cout<<"Test for the find() method: "<<endl;
  cout<<"Testing find(5). If 5 is found, it will return the number 5. If not, "
      "it will return null(INT_MIN)."<<endl;
  cout<< t1.find(5)<<endl;

  cout<<""<<endl;
  cout<<"Test for the remove()method: "<<endl;
  cout<<"Testing remove(3). If 3 is successfully found and removed,"
      " it will return 3. If not, it will return null(INT_MIN)." <<endl;
  cout<< t1.remove(3)<<endl;

  cout<<""<<endl;
  cout<<"Test the getLongestList() method: "<<endl;
  cout<<"(This method will return the number of elements in the longest list)"<<endl;
  cout<< t1.getLongestList()<<endl;

  cout<<""<<endl;
  cout<<"Running the clear() method."<<endl;
  t1.clear();
  cout<<"Checking the size() of the Hash Table. If cleared, should return 0"<<endl;
  cout<<"result: "<< t1.size()<<endl;

}

void checkLinearHash(){
  LinearHashTable<int> t1(INT_MIN,-1);
  cout<<"We will add 30 random numbers between 0 and 10, to the Linear Hash Table: " <<endl;

    int random;
    for(int i = 0; i< 30; i++){
      random = rand()%100;
      cout<<"ADDING THE NUMBER: "<<random<<". does it get added?"<<endl;
      cout<<"(If the element already exists in the table, it does "
          "not get added and returns 0. If it gets added, returns 1.)"<<endl;
      cout<< t1.add(random)<<endl;
    }

    cout<<""<<endl;
    cout<<"Test for the size() method: "<<endl;
    cout<<"What is the size of the Linear Hash Table?"<<endl;
    cout<< t1.size()<<endl;

    cout<<""<<endl;
    cout<<"Test for the find() method: "<<endl;
    cout<<"Testing find(5). If 5 is found, it will return the number 5. If not, "
        "it will return null(INT_MIN)."<<endl;
    cout<< t1.find(5)<<endl;

    cout<<""<<endl;
    cout<<"Test for the remove()method: "<<endl;
    cout<<"Testing remove(3). If 3 is successfully found and removed,"
        " it will return 3. If not, it will return null(INT_MIN)." <<endl;
    cout<< t1.remove(3)<<endl;

    cout<<""<<endl;
    cout<<"Running the clear() method."<<endl;
    t1.clear();
    cout<<"Checking the size() of the Hash Table. If cleared, should return 0"<<endl;
    cout<<"result: "<< t1.size()<<endl;

}

int main() {
    checkChainedHash();
    cout<<""<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<""<<endl;
    checkLinearHash();
  return 0;
}
