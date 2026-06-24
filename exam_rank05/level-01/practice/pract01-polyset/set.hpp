#ifndef SET_HPP
#define SET_HPP

#include "bag.hpp"
#include "searchable_array_bag.hpp"
class set
{
private:
	searchable_bag&		bag_;

	//	OCF
	set();
	set(const set& other);
	set& operator=(const set& other);

public:
	set (searchable_bag& p_bag);
	bool has(int value) const;
	void insert(int value);
	void insert(int *arr, int size);
	void print() const;
	void clear();
	//	getter bag
	const searchable_bag& get_bag();
	~set();
};

#endif
