/*
 * DataStructureTester.h
 *
 *  Created on: Nov 17, 2014
 *      Author: Stefan
 */

#ifndef DATASTRUCTURETESTER_H_
#define DATASTRUCTURETESTER_H_

#include <iostream>
#include "List.h"
#include <time.h>


namespace ods{

template<class T>
class DataStructureTester{
protected:
  T list;

public:
  int doSequentialAdd(int start, int end, int step);
  int doRandomAdd(int n);
  int doSequentialRemove(int start, int end, int step);
  int doRandomRemove(int n);
  int doSequentialFind(int start, int end, int step);
  int doRandomFind(int n);
};

template<class T>
int DataStructureTester<T>::doSequentialAdd(int start, int end, int step){
	clock_t startTime,endTime;
	startTime=clock();
	int i = start;
	while(i <= end){
		list.add(i);
//		std::cout<<list.find(i)<<std::endl;
		i += step;
	}
	endTime=clock();
	int diff = (int)((double)endTime-startTime)/(CLOCKS_PER_SEC/1000);
	return diff;
}

template<class T>
int DataStructureTester<T>::doRandomAdd(int n){
	clock_t startTime, endTime;
	startTime = clock();
	for(int i = 0; i< n; i++){
		srand(i);
			int j = rand();
			list.add(j);
			//std::cout<<list.find(j)<<std::endl;
	}
	endTime = clock();
	int diff = (int)((double)endTime-startTime)/(CLOCKS_PER_SEC/1000);
	return diff;
}

template<class T>
int DataStructureTester<T>::doSequentialRemove(int start, int end, int step){
	clock_t startTime, endTime;
	startTime = clock();
	int i = start;
	while(i<= end){
		list.remove(i);
		i+= step;
	}
	endTime = clock();
	int diff = (int)((double)endTime-startTime)/(CLOCKS_PER_SEC/1000);
	return diff;
}

template<class T>
int DataStructureTester<T>::doRandomRemove(int n){

	clock_t startTime, endTime;
	startTime = clock();
	for(int i = 0; i< n; i++){
		srand(i);
		int j = rand();
		list.remove(j);
		//std::cout<<list.remove(j)<<std::endl;
	}
	endTime = clock();
	int diff = (int)((double)endTime-startTime)/(CLOCKS_PER_SEC/1000);
	return diff;
}

template<class T>
int DataStructureTester<T>::doSequentialFind(int start, int end, int step){
	clock_t startTime, endTime;
	startTime = clock();
	int i = start;
	while(i<= end){
		list.find(i);
		i+=step;
	}
	endTime = clock();
	int diff = (int)((double)endTime-startTime)/(CLOCKS_PER_SEC/1000);
	return diff;
}

template<class T>
int DataStructureTester<T>::doRandomFind(int n){
	clock_t startTime, endTime;
	startTime = clock();
	for(int i = 0; i< n; i++){
		srand(i);
		int j = rand();
		list.find(j);
	}
	endTime = clock();
	int diff = (int)((double)endTime-startTime)/(CLOCKS_PER_SEC/1000);
	return diff;
}
}

#endif /* DATASTRUCTURETESTER_H_ */
