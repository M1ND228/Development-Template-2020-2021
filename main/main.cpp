#include <stdio.h>
#include "stack.h"
#include "multistack.h"
#include "multistackroot .h"

int main() {
	TStack t1;
	TStack t2;
	
	for (int i = 0; i < 5; i++)
	{
		t1.Put(i * 2);
		t2.Put(i + 1);
	}
	t2.Put(10);
	
	t1.print();
	std::cout << "\n";
	t2.print();
	std::cout << "\n";
	std::cout << "\n";
	t1.swap(t1, t2);
	
	t1.print();
	std::cout << "\n";
	t2.print();
	
  return 0;
}