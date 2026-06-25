#include "searchable_tree_bag.hpp"
#include <cstddef>

searchable_tree_bag::searchable_tree_bag()
{
}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& other) : tree_bag(other)
{
}

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& other)
{
	if (this != &other)
	{
		tree_bag::operator=(other);
	}
	return *this;
}

searchable_tree_bag::~searchable_tree_bag()
{
}
//	override
bool searchable_tree_bag::has(int value) const
{
	node* current = tree;

	while (current != NULL)
	{
		if (current->value == value)
		{
			return true;
		}
		else if (value < current->value)
		{
			current = current->l;
		}
		else
		{
			current = current->r;
		}
	}
	return false;
}

