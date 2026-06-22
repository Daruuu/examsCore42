#pragma once

#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class searchable_tree_bag  : public tree_bag, public searchable_bag
{
	public:
	//	OCF
	searchable_tree_bag();
	searchable_tree_bag(const searchable_tree_bag& other);
	searchable_tree_bag& operator=(const searchable_tree_bag& other);
	~searchable_tree_bag();

	// has() from 
	bool has(int value) const;

};
