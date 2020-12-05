#pragma once
#include <list>
#include <iostream>

template<class T>
class Queue
{
private:
	std::list<T> list;
public:
	void push(T val);
	void pop();
	bool empty();
	int size();
	T front();
	T back();

	void print();
};

template<class T>
void Queue<T>::push(T val)
{
	list.push_front(val);
}

template<class T>
 void Queue<T>::pop()
{
	if (empty()) { throw std::out_of_range("Queue is empty"); }
	list.pop_back();
}

 template<class T>
 bool Queue<T>::empty()
 {
	 if (list.size() == 0) { return true; }
	 else { return false; }

 }

template<class T>
 int Queue<T>::size()
{
	return list.size();
}

template<class T>
 T Queue<T>::front()
{
	if (empty()) { throw std::out_of_range("Queue is empty"); }
	return list.back();
}

template<class T>
 T Queue<T>::back()
{
	if (empty()) { throw std::out_of_range("Queue is empty"); }
	return list.front();
}

template<class T>
 void Queue<T>::print()
{

	for (int i = 0; i < size(); i++)
	{
		std::cout << i << " ";
	}
	std::cout << "  size - " << size() << "\n";
}