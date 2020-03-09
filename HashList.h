#pragma once

#include <iostream>
using namespace std;

namespace TwiceCheckHashList
{
enum Result
{
	OK,
	FOUND,
	NOT_FOUND,
	OUT_OF_BOUNDRY,
	BAD_HASH_FUNCTION
};

template <class DataType>
class Item
{
public:
	DataType data;
	bool has_data = false;

public:
	Item();
	Item(const DataType &Data);
};

template <class DataType>
Item<DataType>::Item()
{
	this->has_data = false;
}

template <class DataType>
Item<DataType>::Item(const DataType &Data)
{
	this->data = Data;
	this->has_data = true;
}

template <class DataType>
class HashList
{
private:
	Item<DataType> *list = nullptr;
	int max_size = 0;
	int (*hash_func)(DataType &Data);
	int num = 0;

public:
	HashList(const int Max, int (*HashFunction)(DataType &Data));
	~HashList();
	void Check();

	Result insert(DataType Data);
	Result remove(DataType &Data);
	Result search(DataType &Data, int &p);

	void print() const;
};

template <class DataType>
HashList<DataType>::HashList(const int Max, int (*HashFunction)(DataType &Data))
{
	this->max_size = Max;
	this->hash_func = HashFunction;
	this->list = new Item<DataType>[this->max_size];
	if (this->list == nullptr)
	{
		this->max_size = 0;
	}
}

template <class DataType>
HashList<DataType>::~HashList()
{
	if (this->list != nullptr)
	{
		delete[] this->list;
	}
}

template <class DataType>
void HashList<DataType>::Check()
{
	if (num * 2 >= max_size)
	{
		delete[] this->list;
		max_size = (max_size + 1) * 2;
		this->list = new Item<DataType>[this->max_size];
	}
}

template <class DataType>
Result HashList<DataType>::insert(DataType Data)
{
	int pos = (*hash_func)(Data);
	if (pos >= max_size)
		return BAD_HASH_FUNCTION;
	Check();
	num++;
	int i = 1, next_pos = pos;
	while (list[next_pos].has_data)
	{
		next_pos = (pos + i + max_size) % max_size;
		if (!list[next_pos].has_data)
			break;
		next_pos = (pos + i + max_size) % max_size;
		i *= 2;
	}
	list[next_pos].has_data = true;
	list[next_pos].data = Data;
	return OK;
}

template <class DataType>
Result HashList<DataType>::remove(DataType &Data)
{
	int pos = 0;
	if (search(Data, pos) == NOT_FOUND)
		return NOT_FOUND;
	list[pos].has_data = false;
	return OK;
}

template <class DataType>
Result HashList<DataType>::search(DataType &Data, int &p)
{
	int pos = (*hash_func)(Data);
	if (pos >= max_size)
		return NOT_FOUND;
	int i = 1, next_pos = pos;
	while (list[next_pos].has_data && i <= max_size)
	{
		if (list[next_pos].data == Data)
		{
			p = next_pos;
			return FOUND;
		}
		next_pos = (pos + i + max_size) % max_size;
		if (list[next_pos].data == Data)
		{
			p = next_pos;
			return FOUND;
		}
		next_pos = (pos - i + max_size) % max_size;
		i *= 2;
	}
	return NOT_FOUND;
}

template <class DataType>
void HashList<DataType>::print() const
{
	for (int i = 0; i < this->max_size; i++)
	{
		if (this->list[i].has_data)
		{
			std::cout << "[" << this->list[i].data << "]";
		}
		else
		{
			std::cout << "[ ]";
		}
	}
	std::cout << endl;
}

}; // namespace TwiceCheckHashList
