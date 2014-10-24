/*
 * ChainedHashTable.h
 *
 *  Created on: Oct 21, 2014
 *      Author: stojankz
 */

#ifndef CHAINEDHASHTABLE_H_
#define CHAINEDHASHTABLE_H_
#include <climits>
#include "utils.h"
#include "array.h"
#include "DLList.h"

namespace ods {

template<class T>
class ChainedHashTable {
protected:
  typedef DLList<T> List;
  T null;
  array<List> t;
  int n; //number of elements in the backing array
  int d; //dimension
  int z; //randomly chosen odd integer
  float loadFactor;
  static const int w = 32; //sizeof(int)*8;
  void allocTable(int m);
  void resize();
  int hash(T x) {
    return (((unsigned)(z*x))%(1<<d));
  }

public:
  ChainedHashTable();
  virtual ~ChainedHashTable();
  bool add(T x);
  T remove(T x);
  T find(T x);
  int size() {
    return n;
  }
  void clear();
  void setLoadFactor(float f);
  float getLoadFactor();
  int getLongestList();
};

/**
 * FIXME:  A copy-constructor for arrays would be useful here
 */
template<class T>
void ChainedHashTable<T>::resize() {
  d = 1;
  while (1<<d <= n/loadFactor) d++;
    n = 0;
  array<List> newTable(1<<d);
  for (int i = 0; i < t.length; i++) {
    for (int j = 0; j < t[i].size(); j++) {
      T x = t[i].get(j);
      newTable[hash(x)].add(x);
      n++;
    }
  }
  t = newTable;
}

/*
template<>
ChainedHashTable<int>::ChainedHashTable() : t(2)
{
  n = 0;
  d = 1;
  null = INT_MIN;
  z = rand() | 1;     // is a random odd integer
}
*/


template<class T>
ChainedHashTable<T>::ChainedHashTable() : t(2) {
  n = 0;
  d = 1;
  null = INT_MIN;
  z = rand() | 1;     // is a random odd integer
  loadFactor = 1;
}



template<class T>
ChainedHashTable<T>::~ChainedHashTable() {
}


template<class T>
bool ChainedHashTable<T>::add(T x) {
  if (find(x) != null) return false;
  if (n+1 > loadFactor*t.length) resize();
  t[hash(x)].add(x);
  n++;
  return true;
}


template<class T>
T ChainedHashTable<T>::remove(T x) {
  int j = hash(x);
  for (int i = 0; i < t[j].size(); i++) {
    T y = t[j].get(i);
    if (x == y) {
      t[j].remove(i);
      n--;
      return y;
    }
  }
  return null;
}


template<class T>
T ChainedHashTable<T>::find(T x) {
  int j = hash(x);
  for (int i = 0; i < t[j].size(); i++)
    if (x == t[j].get(i))
      return t[j].get(i);
  return null;
}


template<class T>
void ChainedHashTable<T>::clear() {
  n = 0;
  d = 1;
  array<List> b(2);
  t = b;
}

template<class T>
void ChainedHashTable<T> :: setLoadFactor(float f){
  this->loadFactor = f;
}

template<class T>
float ChainedHashTable<T>::getLoadFactor(){
  return loadFactor;
}

template<class T>
int ChainedHashTable<T> :: getLongestList(){
  int longestList = 0;
  for(int i = 0; i<t.length; i++){
    DLList<T> *pL = &t[i];
    if(pL->size()> longestList){
      longestList = pL->size();
    }
  }
  return longestList;
}

} /* namespace ods */
#endif /* CHAINEDHASHTABLE_H_ */
