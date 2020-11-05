#include "stack.h"

void TStack::SetMem(TElem* _pMem, int Size)
{
	if (MemType == MEM_HOLDER) { delete[] pMem; }
	pMem = _pMem;
	MemType = MEM_RENTER;
	MemSize = Size;
}

TStack::~TStack()
{
	if (MemType == MEM_HOLDER)
	{
		delete[] pMem;
	}
	pMem = nullptr;
}

TStack::TStack(int Size)
{
	Hi = -1;
	DataCount = 0;
	MemSize = Size;
	if (Size == 0)
	{
		pMem = nullptr;
		MemType = MEM_RENTER;
	}
	else
	{
		pMem = new TElem[MemSize];
		MemType = MEM_HOLDER;
	}
}

void TStack::Put(const TData& Val)
{
	if (pMem == nullptr)throw std::exception("������ �� ��������!");
	else if(IsFull()) throw std::exception("���� ��������!");
	else 
	{
		Hi = GetNextIndex(Hi);
		pMem[Hi] = Val;
		DataCount++;
	}
}

TData TStack::Get()
{
	TData temp = -1;
	if (pMem == nullptr)throw std::exception("������ �� ��������!");
	else if (IsEmpty()) throw std::exception("���� ����!");
	else
	{
		temp = pMem[Hi--];
		DataCount--;
	}
	return temp;
}

void TStack::print()
{
	for (int i = 0; i < DataCount; i++)
	{
		std::cout << pMem[i] << " ";
	}
}
