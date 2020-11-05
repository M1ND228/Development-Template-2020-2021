#include "multistack.h"

int TMultistack::StackRelocation(int nst)
{
	int is, ns, ks, k, res = 0;
	pStack[nst]->DataCount++;
	int tmp = FreeMemSize;
	FreeMemSize = GetFreeMemSize();
	if (FreeMemSize > -1)
	{
		res = 1;
		RelocationCount++;
		SetStackRelocation(pStackMem);
		for (ns = 0; ns < StackNum; ns++)
		{
			if (pStackMem[ns] < pStack[ns]->pMem)
			{
				for (k = 0; k < pStack[ns]->DataCount; k++)
				{
					pStackMem[ns][k] = pStack[ns]->pMem[k];
				}
				pStack[ns]->SetMem(pStackMem[ns], pStackMem[ns + 1] - pStackMem[ns]);
			}
			else if (pStackMem[ns] > pStack[ns]->pMem)
			{
				for (ks = ns; pStackMem[ks + 1] > pStack[ks + 1]->pMem; ks++);
				for (is = ks; is >= ns; is--)
				{
					for (k = pStack[is]->DataCount - 1; k >= 0; k--)
					{
						pStackMem[is][k] = pStack[is]->pMem[k];
					}
					pStack[is]->SetMem(pStackMem[is], pStackMem[is + 1] - pStackMem[is]);
				}
			}
			else
			{
				pStack[ns]->SetMem(pStackMem[ns], pStackMem[ns + 1] - pStackMem[ns]);
			}
		}
	}
	pStack[nst]->DataCount--;
	FreeMemSize++;
	return res;
}

int TMultistack::GetFreeMemSize()
{
	FreeMemSize = 0;
	for (int i = 0; i < StackNum; i++)
	{
		FreeMemSize += pStack[i]->MemSize - pStack[i]->DataCount;
	}
	return FreeMemSize;
}

void TMultistack::SetStackRelocation(TElem* pStackMem[])
{
	pStackMem[0] = &Mem[0];
	for (int i = 1; i <= StackNum; i++)
	{
		pStackMem[i] = pStackMem[i - 1] + pStack[i - 1]->DataCount + FreeMemSize / StackNum;
	}
	pStackMem[StackNum] = pStack[StackNum]->pMem;
}

TMultistack::TMultistack()
{
	int Size = MemLim / StackNum;
	for (int i = 0, pos = 0; i <= StackNum; i++, pos += Size)
	{
		pStack[i] = new TStack(0);
		if (i == StackNum - 1)
		{
			pStack[i]->SetMem(&Mem[pos], MemLim - pos);
		}
		if (i == StackNum)
		{
			pStack[i]->SetMem(&Mem[MemLim], 0);
		}
		else
		{
			pStack[i]->SetMem(&Mem[pos], Size);
		}
	}
	RelocationCount = 0;
	FreeMemSize = MemLim;
}

TMultistack::~TMultistack()
{
	for (int i = 0; i < StackNum; i++)
	{
		delete pStack[i];
	}
}

bool TMultistack::IsEmpty(int ns) const { return pStack[ns]->IsEmpty(); }

bool TMultistack::IsFull(int ns) const{	return pStack[ns]->IsFull(); }

void TMultistack::Put(int ns, const TData& Val)
{
	if (pStack[ns]->IsFull())
	{
		if (!StackRelocation(ns))
		{
			throw std::out_of_range("Input error: No free memory");
		}
	}
	pStack[ns]->Put(Val);
	FreeMemSize--;
}

TData TMultistack::Get(int ns)
{
	TData tmp = pStack[ns]->Get();
	FreeMemSize++;
	return tmp;
}





