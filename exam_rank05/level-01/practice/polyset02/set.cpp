#include "set.hpp"

set::set(searchable_bag& s_bag) : p_bag(s_bag)
{}

//	override from searchable_bag
bool set::has(int value) const
{
	return p_bag.has(value);
}

//	override from bag
void set::insert(int value)
{
	if (!has(value))
		p_bag.insert(value);
}
void set::insert(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
		insert(arr[i]);
}

void set::print() const
{
	p_bag.print();
}
void set::clear()
{
	p_bag.clear();
}

const searchable_bag& set::get_bag()
{
	return p_bag;
}
