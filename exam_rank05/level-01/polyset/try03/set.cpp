#include "set.hpp"
#include <cstddef>

set::set() : _bag(NULL) {}

set::set(searchable_bag& bag) : _bag(&bag) {}

set::set(const set& other) : _bag(other._bag) {}

set& set::operator=(const set& other) {
    if (this != &other) {
        _bag = other._bag;
    }
    return *this;
}

set::~set() {}

void set::insert(int value) {
    if (_bag && !_bag->has(value)) {
        _bag->insert(value);
    }
}

void set::insert(int* arr, int size) {
    if (_bag) {
        for (int i = 0; i < size; ++i) {
            if (!_bag->has(arr[i])) {
                _bag->insert(arr[i]);
            }
        }
    }
}

void set::print() const {
    if (_bag) {
        _bag->print();
    }
}

void set::clear() {
    if (_bag) {
        _bag->clear();
    }
}

bool set::has(int value) const {
    if (_bag) {
        return _bag->has(value);
    }
    return false;
}

searchable_bag& set::get_bag() const {
    return *_bag;
}
