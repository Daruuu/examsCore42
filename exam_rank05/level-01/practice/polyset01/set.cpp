#include "searchable_bag.hpp"
#include "set.hpp"

set::set(searchable_bag& s_bag) : bag(s_bag)	// faltaba implementar
{}

const searchable_bag& set::get_bag()
{
	return bag;
}

bool set::has(int value) const
{
	return bag.has(value);
}

//	override de bag
void set::insert(int value)
{
	if (!has(value))
	{
		bag.insert(value);
	}
}

void set::insert(int *arr, int size)
{
	for (int i = 0; i < size; ++i)
		insert(arr[i]);
}

void set::print() const
{
	bag.print();
}

void set::clear()
{
	bag.clear();
}

set::~set()
{
}
