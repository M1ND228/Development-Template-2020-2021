#include <stdio.h>
#include "hashTable.h"

int main() {
  //printf("hello!\n");
  
	HashTable temp1;
	HashTable temp2(10);
  
	temp1.add(7);
	temp1.add(3);
	temp1.add(1);
	temp1.add(0);
	temp1.add(10);

	temp2.add(9);
	temp2.add(50);
	temp2.add(6);
	temp2.add(3);
	temp2.add(4);
	temp2.add(2);

	cout << "STATUS: " << temp2.search(2) << endl;

	temp2.printTable();
	temp2.remove(2);
	temp2.remove(50);

	cout << "STATUS: " << temp2.search(2) << endl;

	//cout << "Default Table" << endl;
	//temp1.printTable();

	cout << "table with size 10" << endl;
	temp2.printTable();

	return 0;
}