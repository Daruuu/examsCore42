#include "set.hpp"
#include <cstddef>

set::set(searchable_bag& bag) : _bag(&bag)
{
}

set::set(const set& other) : _bag(other._bag)
{
}

set& set::operator=(const set& other)
{
	if (this != &other)
	{
		_bag = other._bag;
	}
	return *this;
}

set::~set()
{
}

void set::insert(int value)
{
	if (!has(value))
	{
		_bag.insert(value);
	}
}

void set::insert(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		insert(arr[i]);
	}
}

void set::print() const
{
	bag.print();
}

void set::clear()
{
	bag.clear();
}

bool set::has(int value) const
{
	return bag.has(value);
}

const searchable_bag& set::get_bag()
{
	return _bag;
}
