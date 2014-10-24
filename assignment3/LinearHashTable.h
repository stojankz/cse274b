/*
 * LinearHashTable.h
 *
 *  Created on: Oct 23, 2014
 *      Author: stojankz
 */

#ifndef LINEARHASHTABLE_H_
#define LINEARHASHTABLE_H_
#include <climits>
#include <iostream>
using namespace std;
#include "array.h"
namespace ods {

extern unsigned int tab[4][256];

template<class T>
class LinearHashTable {

  static const int w = 32;
  static const int r = 8;
  array<T> front;
  array<T> back;
  int n;   // number of values in T
  int q;   // number of non-null entries in T
  int d;   // t.length = 2^d
  int z;   // randomly chosen odd integer
  T null, del;
  void resize();
  int hash(T x) {
    return (((unsigned)(z*x))%(1<<d));
  }
  // Sample code for the book only -- never use this
  /*
  int idealHash(T x) {
    return tab[hashCode(x) >> w-d];
  }
  */


public:
  // FIXME: get rid of default constructor
  LinearHashTable();
  LinearHashTable(T null, T del);
  virtual ~LinearHashTable();
  bool add(T x);
  bool addSlow(T x);
  T remove(T x);
  T find(T x);
  int size() { return n; }
  void clear();
  // FIXME: yuck
  void setNull(T null) { this->null = null; front.fill(null); }
  void setDel(T del) { this->del = del; }
};

/*
template<>
LinearHashTable<int>::LinearHashTable() : t(2, INT_MIN) {
  null = INT_MIN;
  del = INT_MIN + 1;
  n = 0;
  q = 0;
  d = 1;
}
*/

/**
 * FIXME: Dangerous - leaves null and del uninitialized
 */
template<class T>
LinearHashTable<T>::LinearHashTable() : front(2) {
/*
  this->null = null;
  this->del = del;
*/
  n = 0;
  q = 0;
  d = 1;
  z = rand() | 1;
}


template<class T>
LinearHashTable<T>::LinearHashTable(T null, T del) : front(2,null),back(2,null) {
  this->null = null;
  this->del = del;
  n = 0;
  q = 0;
  d = 1;
  z = rand() | 1;
}


template<class T>
LinearHashTable<T>::~LinearHashTable() {
}

template<class T>
void LinearHashTable<T>::resize() {
  d = 1;
  while ((1<<d) < 3*n) d++;
  array<T> tnew(1<<d, null);
  q = n;
  // insert everything into tnew
  for (int k = 0; k < front.length; k++) {
    if (front[k] != null && front[k] != del) {
      int m = 1<<d;
      int i = 0;
      int probe = (hash(k) + i*(1+hash(k)%(m-1)))%m;
      while (tnew[probe] != null){
        i = (i == tnew.length-1) ? 0 : i + 1;
        probe = (hash(k) + i*(1+hash(k)%(m-1)))%m;
      }
      tnew[probe] = front[k];
    }
  }
  front = tnew;
}

template<class T>
void LinearHashTable<T>::clear() {
  n = 0;
  q = 0;
  d = 1;
  array<T> tnew(2, null);
  array<T> tnew2(2,null);
  front = tnew;
  back = tnew2;
}

template<class T>
bool LinearHashTable<T>::add(T x) {
  if (find(x) != null) return false;
  if (2*(q+1) > front.length) resize();   // max 50% occupancy
  int i = 0;
  int m = 1<<d;
  int probe = (hash(x) + i*(1+hash(x)%(m-1)))%m;
  while (front[probe] != null && front[probe] != del){
    i = (i == front.length-1) ? 0 : i + 1; // increment i
    probe = (hash(x) + i*(1+hash(x)%(m-1)))%m;
  }
  if (front[probe] == null) q++;
  n++;
  front[probe] = x;
  return true;
}

//I attempted to write the add function with 2 backing
//arrays but encountered an error. I did not have enough time
//to figure them out and finish.
//
//template<class T>
//bool LinearHashTable<T>::add(T x){
//  if(find(x) == x) return false;
//  if(2*(q+1) > front.length + back.length) resize();
//
//  int i = 0;
//  int m = 1<<d;
//  int probe = (hash(x) + i*(1+hash(x)%(m-1)))%m;
//
//  if(probe < front.length){
//    while(probe<front.length && front[probe] != null && front[probe] != del){
//      i = (i == front.length + back.length-1) ? 0 : i + 1; // increment i
//      probe = (hash(x) + i*(1+hash(x)%(m-1)))%m;
//    }
//    if(probe>front.length){
//      goto 185;
//    }
//    q++;
//    n++;
//    front[probe] = x;
//    return true;
//  }
//  else{
//    while(back[probe-front.length] != null && back[probe-front.length] != del){
//      i = (i == front.length + back.length-1) ? 0 : i + 1; // increment i
//      probe = (hash(x) + i*(1+hash(x)%(m-1)))%m;
//    }
//    if(probe<front.length){
//          goto 172;
//        }
//    q++;
//    n++;
//    back[probe-front.length] = x;
//    return true;
//  }
//}


template<class T>
T LinearHashTable<T>::find(T x) {
  int i = 0;
  int m = 1<<d;
  int probe = (hash(x) + i*(1+hash(x)%(m-1)))%m;
  while (front[probe] != null) {
    if (front[probe] != del && front[probe] == x) return front[probe];
    i = (i == front.length-1) ? 0 : i + 1; // increment i
    probe = (hash(x) + i*(1+hash(x)%(m-1)))%m;
  }
  return null;
}

//My find method for 2 backing arrays
//
//template<class T>
//T LinearHashTable<T>::find(T x){
//  int i = 0;
//  int m = 1<<d;
//  int probe = (hash(x) + i*(1+hash(x)%(m-1)))%m;
//
//  if(probe < front.length){
//    while(probe< front.length && front[probe] != null){
//      if(front[probe] != del && front[probe] == x) return front[probe];
//      i = (i == front.length + back.length-1) ? 0 : i + 1;
//      probe = (hash(x) + i *(1+hash(x) %(m-1)))%m;
//    }
//  }
//  else{
//    while(back[probe-front.length] != null){
//      if(back[probe-front.length] != del && back[probe-front.length] == x) return back[probe-front.length];
//      i = (i == front.length +back.length-1) ? 0 : i + 1;
//      probe = (hash(x) + i *(1+hash(x) %(m-1)))%m;
//    }
//  }
//  return null;
//}

template<class T>
T LinearHashTable<T>::remove(T x) {
  int i = 0;
  int m = 1<<d;
  int probe =(hash(x) + i*(1+hash(x)%(m-1)))%m;
  while (front[probe] != null) {
    T y = front[probe];
    if (y != del && x == y) {
      front[probe] = del;
      n--;
      if (8*n < front.length) resize(); // min 12.5% occupancy
      return y;
    }
    i = (i == front.length-1) ? 0 : i + 1;  // increment i
    probe = (hash(x) + i*(1+hash(x)%(m-1)))%m;
  }
  return null;
}

//My remove method for two backing arrays
//
//template<class T>
//T LinearHashTable<T>::remove(T x){
//  int i = 0;
//  int m = 1<<d;
//  int probe = (hash(x) + i*(1+hash(x)%(m-1)))%m;
//
//  if(probe<front.length){
//    while(probe<front.length && front[probe] != null){
//      T y = front[probe];
//      if(y != del && x == y){
//        front[probe] = del;
//        n--;
//        if(8*n < front.length+back.length) resize();
//        return y;
//      }
//      i = (i == front.length + back.length-1) ? 0 : i + 1;  // increment i
//      probe = (hash(x) + i*(1+hash(x)%(m-1)))%m;
//    }
//  }
//    else{
//      while(back[probe-front.length] != null){
//        T y = back[probe - front.length];
//        if(y != del && x == y){
//          back[probe-front.length] = del;
//          n--;
//          if(8*n < front.length+back.length) resize();
//          return y;
//        }
//      }
//      i = (i == front.length+back.length-1) ? 0 : i + 1;  // increment i
//      probe = (hash(x) + i*(1+hash(x)%(m-1)))%m;
//    }
//return null;
//}

template<class T>
bool LinearHashTable<T>::addSlow(T x) {
  if (2*(q+1) > front.length) resize();   // max 50% occupancy
  int i = 0;
  int m = 1<<d;
  int probe = (hash(x) + i*(1+hash(x)%(m-1)))%m;
  while (front[probe] != null) {
      if (front[probe] != del && x.equals(front[probe])) return false;
      i = (i == front.length-1) ? 0 : i + 1; // increment i
      probe = (hash(x) + i*(1+hash(x)%(m-1)))%m;
  }
  front[probe] = x;
  n++; q++;
  return true;
}

//template<class T>
//void LinearHashTable<T> ::CheckBalance(){
//  //for(..)
//}

} /* namespace ods */
#endif /* LINEARHASHTABLE_H_ */
