#pragma once

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

public:
	HashList(const int Max, int (*HashFunction)(DataType &Data));
	~HashList();

	Result insert(DataType &Data);
	Result remove(DataType &Data);
	Result search(DataType &Data);
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
Result HashList<DataType>::insert(DataType &Data)
{
}

template <class DataType>
Result HashList<DataType>::remove(DataType &Data)
{
}

template <class DataType>
Result HashList<DataType>::search(DataType &Data)
{
}

}; // namespace TwiceCheckHashList
