#pragma once

#include <exception>
#include <iostream>

typedef int TElem;
typedef TElem* PTElem;
typedef int TData;

#define DefMemSize 25

enum TMemType 
{
	MEM_HOLDER, MEM_RENTER
};

class TStack
{
protected:
	PTElem pMem;
	int MemSize;
	int DataCount;
	TMemType MemType;
	int Hi;
protected:
	void SetMem(TElem* _pMem, int Size);
	int GetNextIndex(int index) { return ++index; };
public:
	~TStack();
	TStack(int Size = DefMemSize);
	int IsEmpty()const { return DataCount == 0; };
	int IsFull()const { return DataCount == MemSize; };
	void Put(const TData& Val);
	TData Get();
	void swap(TStack& first, TStack& second);
	void print();
	friend class TMultistack;
	friend class TMultiRoot;
};