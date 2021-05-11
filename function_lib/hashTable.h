#include <iostream>
#define SIZE 100

using namespace std;

enum Status { EMPTY, OCCUPIED, DELETED };

struct Hash
{
	int key;
	Status status;
};

class HashTable
{
	Hash* data;		// Массив ключей
	int size;		// Выделено памяти
	int count;		// Количество элементов

	int hash(int _key, int p) { return (_key + p) % size; }
	string GetStatus(int index);
public:
	HashTable();
	HashTable(int _size);
	~HashTable();

	void add(int _key);
	void remove(int _key);
	bool find(int _key);

	void printTable();
};