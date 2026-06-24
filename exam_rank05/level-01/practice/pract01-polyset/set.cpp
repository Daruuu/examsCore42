#include "set.hpp"
#include <cstddef>

//public:

set::set(searchable_bag& p_bag) : bag_(p_bag)
{
}

bool set::has(int value) const
{
	return bag_.has(value);
}

void set::insert(int value)
{
	if (!has(value))
		bag_.insert(value);
}

void set::insert(int *arr, int size)
{
	for (int i = 0; i < size; ++i)
		insert(arr[i]);
}

void set::print() const
{
	bag_.print();
}

void set::clear()
{
	bag_.clear();
}
//	getter bag
const searchable_bag& set::get_bag()
{
	return bag_;
}
set::~set()
{}
