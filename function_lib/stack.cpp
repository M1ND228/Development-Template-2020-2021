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
	if (pMem == nullptr)throw std::exception("память не выделена!");
	else if(IsFull()) throw std::exception("стек заполнен!");
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
	if (pMem == nullptr)throw std::exception("память не выделена!");
	else if (IsEmpty()) throw std::exception("стек пуст!");
	else
	{
		temp = pMem[Hi--];
		DataCount--;
	}
	return temp;
}

void TStack::swap(TStack& first, TStack& second)
{
	if (first.MemSize != second.MemSize)
	{
		throw std::exception("Разное количество памяти у стеков");;
	}
	TStack tmpF;
	TStack tmpS;
	for (int i = 0; i < first.MemSize; i++)		// Zapis first
	{
		if (first.IsEmpty()) { break; }
		tmpF.Put(first.Get());
	}
	for (int i = 0; i < second.MemSize; i++)	// Zapis second 
	{
		if (second.IsEmpty()) { break; }
		tmpS.Put(second.Get());
	}

	for (int i = 0; i < tmpS.MemSize; i++)		// Swap first <- second
	{
		if (tmpS.IsEmpty()) { break; }
		first.Put(tmpS.Get());
	}
	for (int i = 0; i < tmpF.MemSize; i++)      // Swap first -> second
	{
		if (tmpF.IsEmpty()) { break; }
		second.Put(tmpF.Get());
	}
}

void TStack::print()
{
	for (int i = 0; i < DataCount; i++)
	{
		std::cout << pMem[i] << " ";
	}
}
