#include "searchable_bag.hpp"
#include "bag.hpp"

class set
{
	private:
		searchable_bag& p_bag;
		set();
		set(const set& other);
		set& operator=(const set& other);

public:
	set(searchable_bag& s_bag);
	bool has(int value) const;

	void insert (int value);
	void insert (int *arr, int size);
	void print() const;
	void clear();
	const searchable_bag& get_bag();

	~set();
};

