#pragma once

#include "searchable_bag.hpp"

class set {
private:
    searchable_bag& _bag;
	set();
	set(const set& other);
	set& operator=(const set& other);

public:
    set(searchable_bag& bag);

    void insert(int value);
    void insert(int* arr, int size);
    void print() const;
    void clear();
    bool has(int value) const;

    const searchable_bag& get_bag();
	~set();
};
