#include <iostream>
#include <list>
#include <stack>
#include <string>

std::_List_node<int, void*>* findLoop_HareAndTurtle(std::list<int>& list, int& startPositionLoop)
{
	// If list empty -> exit
	if (list.begin()._Ptr == list.end()._Ptr) { return nullptr; }
	startPositionLoop = 0;
	// Start position
	std::list<int>::iterator hare   = list.begin();
	std::list<int>::iterator turtle = list.begin();
	// End position
	std::list<int>::iterator end    = list.end();

	while (true)
	{
		if (hare == end || turtle == end) return nullptr;

		hare++; turtle++;

		if (hare == end) return nullptr; 

		hare++;

		if (turtle == hare) { return turtle._Ptr; }
		startPositionLoop++;
	}
}

bool findLoop_ReversingPointer(std::list<int>& list) {
	std::_List_node<int, void*>* previousNode = nullptr;
	std::_List_node<int, void*>* currentNode = list.begin()._Ptr;
	std::_List_node<int, void*>* startNode = list.begin()._Ptr;
	std::_List_node<int, void*>* nextNode = nullptr;

	if (!currentNode->_Next) return false;
	while (currentNode != list.end()._Ptr && currentNode) 
	{
		nextNode = currentNode->_Next;
		currentNode->_Next = previousNode;
		previousNode = currentNode;
		currentNode = nextNode;
	}

	if (previousNode == startNode)
	{
		previousNode = nullptr;
		currentNode = list.begin()._Ptr;
		startNode = list.begin()._Ptr;
		while (currentNode != list.end()._Ptr && currentNode) 
		{
			nextNode = currentNode->_Next;
			currentNode->_Next = previousNode;
			previousNode = currentNode;
			currentNode = nextNode;
		}
		return true;
	}
	else
	{
		currentNode = previousNode;
		previousNode = nullptr;
		while (previousNode != startNode)
		{
			nextNode = currentNode->_Next;
			currentNode->_Next = previousNode;
			previousNode = currentNode;
			currentNode = nextNode;
		}
		return false;
	}

}

bool findLoop_KnownSize(std::list<int>& list, int& startPositionLoop)
{
	// If list empty -> exit
	if (list.begin()._Ptr == list.end()._Ptr) { return 0; }

	std::list<int>::iterator firstElem = list.begin();

	std::stack<int> tmp;
	startPositionLoop = -1;
	int i = 0;
	while (true)
	{
		if (firstElem == list.end()) { return false; }
		tmp.push(firstElem._Ptr->_Myval);
		firstElem++;
		if (i >= list.size()) { return true; }
		i++; startPositionLoop++;
	}
}


std::string ListLoopLen(int startPositionLoop)
{
	return  std::to_string(startPositionLoop);
}

void CreateLoop(std::list<int>& list)
{
	auto lastLink = (--list.end())._Ptr;

	for (int countElements = 0; countElements < list.size(); countElements++)
	{
			// Resume from the beginning
		if (countElements == list.size() - 1)
		{
			lastLink->_Next = list.begin()._Ptr;
			break;
		}

	}	
}


void checkReturnValue(int IsOk)
{
	if (IsOk > 0)
	{
		std::cout << "The list contained a loop\n";
	}
	else { std::cout << "Normal list\n"; }
}

int main()
{
	std::list<int> list;

	int counterList = 0;
	
	for (int i = 0; i < 5; i++)
		list.push_back(i * 2);
	
	CreateLoop(list);


	std::list<int> list_2 = {1,2,3,4,5};

	if(findLoop_HareAndTurtle(list, counterList) == nullptr)
		std::cout << "Normal list\n";
	else std::cout << "The list contained a loop\n";
	std::cout << "Number of links - " << ListLoopLen(counterList) << "\n";

	std::cout << "\n";

	if (findLoop_HareAndTurtle(list_2, counterList) == nullptr)
		std::cout << "Normal list\n";
	else std::cout << "The list contained a loop\n";
	std::cout << "Number of links - " << ListLoopLen(counterList) << "\n";

	std::cout << "\n";

	checkReturnValue(findLoop_KnownSize(list, counterList));
	std::cout << "Number of links - " << ListLoopLen(counterList) << "\n";

	std::cout << "\n";

	checkReturnValue(findLoop_KnownSize(list_2, counterList));
	std::cout << "Number of links - " << ListLoopLen(counterList) << "\n";

	std::cout << "\n";

	checkReturnValue(findLoop_ReversingPointer(list));

	checkReturnValue(findLoop_ReversingPointer(list_2));

	std::cout << "\n";

	return 0;
}