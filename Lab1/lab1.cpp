//============================================================================
// Name        : lab1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "rectangle.h"

using namespace std;

int main () {
  Rectangle rect;

  Rectangle &refRect = rect;
  Rectangle rect2 = rect;
  Rectangle *pRect = new Rectangle();
  pRect->set_values(7,8);


  rect.set_values (3,4);
  rect2.set_values (5,6);
  refRect.set_values(10,5);

  cout << "area: " << rect.area() << endl;
  cout << "area2: " << rect2.area()<<endl;
  cout << "pointer to rect " << pRect << endl;
  cout << "area for pointer " << pRect->area() <<endl;
  return 0;
}


