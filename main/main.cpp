#include <stdio.h>
#include "Queue.h"


int main() {
  
  Queue<int> q;
  std::cout << "Test queue:\n";
 
  std::cout << "Test empty with empty queue - " << q.empty() << std::endl;

  std::cout << "Push elements with queue\n\n";
  for (int i = 0; i < 5; i++)
  {
	  q.push(i);
	  q.print();
  }

  std::cout << "\nTest empty after push elemets in queue - " << q.empty() << std::endl << std::endl;

  std::cout << "Test front and back - " << q.front() << " / " << q.back() << std::endl << std::endl;
  
  std::cout << "Remove elemets and check - " << std::endl << std::endl;

  while (!q.empty())
  {
	  q.print();
	  q.pop();
  }

  std::cout << "\nTest empty with empty queue after remove element - " << q.empty() << std::endl;

  system("pause");
  return 0;
}