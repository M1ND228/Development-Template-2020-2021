#pragma once
#include "TNode.h"
#include <vector>

template<typename T>
class TList
{
protected:
	TNode<T>* pFirst;
	TNode<T>* pLast;
	int ListLen;
public:
	TList();
	~TList();
	int GetListLenght();
	bool IsEmpty();
	void InsFirst(T Val);
	void InsLast(T Val);
	void DelFirst();
	void DelLast();
	void DelList();
	void InsValue(T Val, int pos);
	void DelValue(int pos);
	void print();

	bool search(T data);
	void Reverse();
	T get(int pos);
	void Merge(TList<T>& list1, TList<T>& list2);
	bool IsSort();
	void swap(int posFirst, int posSecond);

	void MergerLists(TList<T>& list1, TList<T>& list2);
};

template<typename T>
TList<T>::TList()
{
	pFirst = nullptr;
	pLast = nullptr;
	ListLen = 0;
}

template<typename T>
TList<T>::~TList<T>() { DelList(); }

template<typename T>
int TList<T>::GetListLenght() { return ListLen; }

template<typename T>
bool TList<T>::IsEmpty()
{
	if (ListLen == 0) { return true; }
	else { return false; }
}

template<typename T>
void TList<T>::InsFirst(T Val)
{
	if (pFirst == nullptr)
	{
		pFirst = new TNode<T>(Val);
		pLast = pFirst;
	}
	else
	{
		TNode<T>* newNode = new TNode<T>(Val, pFirst);
		pFirst = newNode;
	}
	ListLen++;
}

template<typename T>
void TList<T>::InsLast(T Val)
{
	if (pFirst == nullptr)
	{
		pFirst = new TNode<T>(Val);
		pLast = pFirst;
	}
	else
	{
		TNode<T>* tmp = new TNode<T>(Val);
		pLast->Next = tmp;
		pLast = tmp;
	}
	ListLen++;
}

template<typename T>
void TList<T>::DelFirst()
{
	if (pFirst == nullptr)
	{
		return;
	}
	if (pFirst == pLast)
	{
		delete pFirst;
		pFirst = nullptr;
		pLast = nullptr;
		ListLen--;
		return;
	}
	TNode<T>* tmp = pFirst;
	pFirst = pFirst->Next;
	delete tmp;
	ListLen--;
}

template<typename T>
void TList<T>::DelLast()
{
	if (pFirst == nullptr)
	{
		return;
	}
	if (pFirst == pLast)
	{
		delete pFirst;
		pFirst = nullptr;
		pLast = nullptr;
		ListLen--;
		return;
	}
	TNode<T>* tmp = pFirst;
	while (tmp->Next->Next != nullptr)
	{
		tmp = tmp->Next;
	}
	delete tmp->Next;
	tmp->Next = nullptr;
	pLast = tmp;
	ListLen--;
}

template<typename T>
void TList<T>::DelList()
{
	while (ListLen != 0) { DelLast(); }
}

template<typename T>
void TList<T>::InsValue(T Val, int pos)
{
	if (pos < 0)
	{
		return;
	}
	if (pos == 0)
	{
		InsFirst(Val);
		return;
	}
	if (pos >= ListLen)
	{
		InsLast(Val);
		return;
	}
	int count = 0;
	TNode<T>* tmp = pFirst;
	while (count != pos - 1)
	{
		tmp = tmp->Next;
		count++;
	}
	TNode<T>* newNode = new TNode<T>(Val, tmp->Next);
	tmp->Next = newNode;
	ListLen++;
}

template<typename T>
void TList<T>::DelValue(int pos)
{
	if (pos < 0 || pos >= ListLen)
	{
		return;
	}
	if (pos == 0)
	{
		DelFirst();
		return;
	}
	if (pos == ListLen - 1)
	{
		DelLast();
		return;
	}
	TNode<T>* tmp = pFirst;
	int count = 0;
	while (count != pos - 1)
	{
		tmp = tmp->Next;
		count++;
	}
	TNode<T>* tmp2 = tmp->Next->Next;
	delete tmp->Next;
	tmp->Next = tmp2;
	ListLen--;
}

template<typename T>
void TList<T>::print()
{
	if (pFirst != nullptr)
	{
		TNode<T>* tmp = pFirst;
		while (tmp->Next != nullptr)
		{

			std::cout << tmp->data << "->";
			tmp = tmp->Next;
		}
		std::cout << tmp->data << "->";
	}
	std::cout << "List length - " << GetListLenght() << "\n";
}

template<typename T>
bool TList<T>::search(T data)
{
	if (ListLen == 0)
	{
		return false;
	}
	if (ListLen == 1)
	{
		if (pFirst->data == data)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	TNode<T>* tmp = pFirst;
	while (tmp->Next != nullptr)
	{
		if (tmp->data == data)
		{
			return true;
		}
		tmp = tmp->Next;
	}
	if (tmp->data == data)
	{
		return true;
	}
	return false;
}

template<typename T>
void TList<T>::Reverse()
{
	for (int i = 0; i < ListLen / 2; i++)
	{
		swap(i, ListLen - i - 1);
	}

}

template<typename T>
T TList<T>::get(int pos)
{
	if (pos < 0 || pos >= ListLen)
	{
		throw std::out_of_range("Input error: invalide input value");
	}
	TNode<T>* tmp = pFirst;
	int count = 0;
	while (count != pos)
	{
		tmp = tmp->Next;
		count++;
	}
	return tmp->data;

}

template<typename T>
void TList<T>::Merge(TList<T>& list1, TList<T>& list2)
{
	if (!list1.IsSort() || !list2.IsSort())
	{
		throw std::logic_error("List is sort");
	}
	DelList();
	while (!list1.IsEmpty() && !list2.IsEmpty())
	{
		if (list1.get(0) < list2.get(0))
		{
			InsLast(list1.get(0));
			list1.DelFirst();
		}
		else
		{
			InsLast(list2.get(0));
			list2.DelFirst();
		}
	}
	while (!list1.IsEmpty())
	{
		InsLast(list1.get(0));
		list1.DelFirst();
	}
	while (!list2.IsEmpty())
	{
		InsLast(list2.get(0));
		list2.DelFirst();
	}

}

template<typename T>
bool TList<T>::IsSort()
{
	for (int i = 0; i < ListLen - 1; i++)
	{
		if (get(i) > get(i + 1))
		{
			return false;
		}
	}
	return true;
}

template<typename T>
void TList<T>::swap(int posFirst, int posSecond)
{
	if (posFirst < 0 || posFirst >= ListLen || posSecond < 0 || posSecond >= ListLen)
	{
		throw std::out_of_range("Input error: invalide input value");
	}
	T T1 = get(posFirst);
	T T2 = get(posSecond);
	TNode<T>* tmp = pFirst;
	int count = 0;
	while (count < posFirst)
	{
		tmp = tmp->Next;
		count++;
	}
	tmp->data = T2;
	count = 0;
	tmp = pFirst;
	while (count < posSecond)
	{
		tmp = tmp->Next;
		count++;
	}
	tmp->data = T1;
}

template<typename T>
void TList<T>::MergerLists(TList<T>& list1, TList<T>& list2)
{
	if (list1.IsEmpty() || list2.IsEmpty()) { throw std::logic_error("Input error: List is empty"); }

	int sizeListFirst = list1.GetListLenght();		// Size List1
	int sizeListSecond = list2.GetListLenght();		// Size List2

	int* dataAll = new int[sizeListFirst + sizeListSecond];		// Arr for all elements list1 + list2

	int i = 0;
	while (i < sizeListFirst)				// Write elements is list1
	{
		dataAll[i] = list1.pLast->data;
		list1.DelLast();
		i++;
	}

	i = 0;
	int* data2 = new int[sizeListSecond];
	while (i < sizeListSecond)				// Write elements is list2
	{
		data2[i] = list2.pLast->data;
		dataAll[sizeListFirst + i] = list2.pLast->data;
		list2.DelLast();
		i++;
	}

	i = 0;
	while (i < sizeListSecond)				// remove elements in list2
	{
		list2.InsLast(data2[i]);
		i++;
	}
	delete[] data2;
	
	std::vector<int> all;					// vector for all elements
	for (int i = 0; i < sizeListFirst + sizeListSecond; i++)
	{
		all.push_back(dataAll[i]);
	}
	
	std::vector<int> resault;				// vector for unique elements
	for (int i = 0; i < all.size(); i++)
	{
		auto pos = std::find(resault.begin(), resault.end(), all[i]);
		if (pos == resault.end())
		{
			resault.push_back(all[i]);
		}
	}
	
	for (int i = 0; i < resault.size(); i++)	// push elements in list1
	{
		list1.InsLast(resault[i]);
	}
	delete[] dataAll;
}
