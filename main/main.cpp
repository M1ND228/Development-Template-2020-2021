#include <stdio.h>
#include <iostream>
#include "TList.h"

int main() {

	std::cout << "\nCreate List 1 and 2\n";
	TList<int> list1;
	TList<int> list2;

	list1.InsFirst(1);
	list1.InsFirst(9);
	list1.InsFirst(3);
	list1.InsFirst(2);
	list1.InsFirst(1);

	list2.InsFirst(1);
	list2.InsFirst(6);
	list2.InsFirst(7);
	list2.InsFirst(9);
	list2.InsFirst(2);
	list2.InsFirst(6);

	list1.MergerLists(list1, list2);

	std::cout << "\nCheck list1 after MergerLists\n";
	list1.print();

	std::cout << "\nCheck list2 after MergerLists (not change)\n";
	list2.print();

	TList<int> list3;
	TList<int> list4;
	for (int i = 0; i < 10; i++)
	{
		list3.InsFirst(1);
		list4.InsFirst(1);
	}

	list3.MergerLists(list3, list4);
	std::cout << "\nCheck list3 after MergerLists only 1\n";
	list3.print();

	/*
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
	*/
	return 0;
}