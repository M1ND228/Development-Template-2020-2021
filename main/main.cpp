#include <stdio.h>
#include <iostream>
#include "TList.h"

int main() {


  std::cout << "Create List\n";
  TList<int> list;

  std::cout << "Input 5 first\n";
  list.InsFirst(5);

  std::cout << "Input 8 first\n";
  list.InsFirst(8);

  std::cout << "Input 1 first\n";
  list.InsFirst(1);

  std::cout << "\nCheck value inside list only first\n";
  list.print();

  std::cout << "\nInput 100 last\n";
  list.InsLast(100);

  std::cout << "Input 3 last\n";
  list.InsLast(3);

  std::cout << "Input 0 first\n";
  list.InsFirst(0);

  std::cout << "\nCheck value inside list\n";
  list.print();

  std::cout << "\nDelete first, and last value\n";
  list.DelFirst();
  list.DelLast();

  std::cout << "Check value inside list\n";
  list.print();

  std::cout << "\nDelete first, and last value\n";
  list.DelFirst();
  list.DelLast();

  std::cout << "Check value inside list\n";
  list.print();

  std::cout << "\nDelete all list, and check\n";
  list.DelList();
  list.print();

  return 0;
}