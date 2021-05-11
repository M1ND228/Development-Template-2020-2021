#include "hashTable.h"

string HashTable::GetStatus(int index)
{
	switch (data[index].status)
	{
	case 0:
		return "EMPTY";
		break;
	case 1:
		return "OCCUPIED";
		break;
	case 2:
		return "DELETED";
		break;
	default:
		break;
	}
}

HashTable::HashTable()
{
	data = new Hash[SIZE];
	size = SIZE;
	count = 0;
	for (int i = 0; i < size; ++i)
	{
		data[i].key = 0;
		data[i].status = EMPTY;
	}
}

HashTable::HashTable(int _size)
{
	data = new Hash[_size];
	size = _size;
	count = 0;
	for (int i = 0; i < _size; ++i)
	{
		data[i].key = 0;
		data[i].status = EMPTY;
	}
}

HashTable::~HashTable()
{
	delete data;
}

void HashTable::add(int _key)
{
	int index;
	index = hash(_key, 0);

	if (data[index].status == OCCUPIED)
	{
		for (int i = 0; i < size; i++)
		{
			index = hash(_key, i * i);
			if (data[index].status != OCCUPIED)
				break;
		}
	}
	// доп случай не нашли €чейку, count == size
	data[index].key = _key;
	data[index].status = OCCUPIED;
}

void HashTable::remove(int _key)
{
}

bool HashTable::find(int _key)
{
	return false;
}

void HashTable::printTable()
{
	cout << "Index" << "\t" << "Data" << "\t" << "Status" << endl;

	for (int i = 0; i < size; i++)
	{
		cout << i << "\t" << data[i].key << "\t" << GetStatus(i) << endl;
	}
}


