#include "set.hpp"
#include <cstddef>

//searchable_bag* bag_;

	//	OCF
set::set()
{
	bag_ = NULL;
}

set::set(searchable_bag& bag) : bag_(&bag)
{}

set::set(const set& other) : bag_(other.bag_)
{}

set& set::operator=(const set& other)
{
	if (this != &other)
	{
		bag_ = other.bag_;
	}
	return *this;
}
set::~set()
{}

void set::insert(int value)
{
	if (bag_ && !bag_->has(value))
	{
		bag_->insert(value);
	}
}

void set::insert(int* array, int size)
{
	if (bag_)
	{
		for (int i = 0; i < size; ++i)
		{
			if(!bag_->has(array[i]))
				bag_->insert(array[i]);
		}
	}
}

void set::print() const
{
	if (bag_)
	{
		bag_->print();
	}
}

void set::clear()
{
	if (bag_)
	{
		bag_->clear();
	}
}

bool set::has(int value) const
{
	if (bag_)
	{
		return bag_->has(value);
	}
	return false;
}

//	get  pointer
searchable_bag& set::get_bag() const	
{
	return *bag_;
}
