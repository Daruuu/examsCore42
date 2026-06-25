#include "searchable_array_bag.hpp"

//class searchable_array_bag : public array_bag, public searchable_bag
	//	OCF
searchable_array_bag::searchable_array_bag()
{
}

searchable_array_bag::searchable_array_bag(const searchable_array_bag& other) : array_bag(other)
{
}

searchable_array_bag& searchable_array_bag::operator=(const searchable_array_bag& other)
{
	if (this != &other)
	{
		array_bag::operator=(other);
	}
	return *this;
}

searchable_array_bag::~searchable_array_bag()
{
}

//	override
bool searchable_array_bag::has(int value) const
{
	for (int i = size; i < size; ++i)
	{
		if (data[i] == value)
			return true;
	}
	return false;
}

