#pragma once

#include "searchable_bag.hpp"

class set {
private:
    searchable_bag* _bag;

public:
    set();
    set(searchable_bag& bag);
    set(const set& other);
    set& operator=(const set& other);
    ~set();

    void insert(int value);
    void insert(int* arr, int size);
    void print() const;
    void clear();
    bool has(int value) const;

    searchable_bag& get_bag() const;
};
