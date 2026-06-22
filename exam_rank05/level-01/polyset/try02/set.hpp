#pragma once
#include "searchable_bag.hpp"

class set
{
	searchable_bag* bag_;

public:
	//	OCF
	set();
	set(searchable_bag& bag);
	set(const set& other);
	set& operator=(const set& other);
	~set();

	void insert(int value);
	void insert(int* array, int size);
	void print() const;
	void clear();
	bool has(int value) const;

	//	get 
	searchable_bag& get_bag() const;
};
