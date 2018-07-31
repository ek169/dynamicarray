#include <iostream>
#include "dynamicArray.h"
using namespace std;

int main(void)
{
  cout << "hello" << endl;
  DynamicArray d1;
  DynamicArray d2;
  d1.addItem(5);
  d1.addItem(7);
  d1.addItem(9);
  d1.addItem(11);
  cout << "Printing d1" << endl;
  d1.print();
  d2.addItem(4);
  d2.addItem(6);
  d2.addItem(8);
  d2.addItem(10);
  cout << "Printing d2" << endl;
  d2.print();
  d2+2;
  cout << "Printing d2 after d2+2" << endl;
  d2.print();
  DynamicArray d3(d2);
  cout << "Printing d3 after copy constructor of d2" << endl;
  d3.print();
  d2 = d1;
  cout << "Printing d2 after assignment to d1" << endl;
  d2.print();
  d1+2;
  cout << "Printing d1 after d1+2" << endl;
  d1.print();
  cout << "Printing d2" << endl;
  d2.print();
  cout << "Printing min, max, average of d2" << endl;
  cout << "min: " << d2.min() << ", max: " << d2.max() << ", avg: " \
  << d2.average() << endl;
  cout << "Indexing 0 and 1 from d1" << endl;
  cout << d1[0] << " " << d1[1] << endl;
  cout << "head 5 d3" << endl;
  d3.head(5);
  cout << "tail 3 d2" << endl;
  d2.tail(3);
  int intArr[5] = {99, 98, 97, 96, 95};
  DynamicArray d4(intArr, 5);
  cout << "Printing d4" << endl;
  d4.print();






}
