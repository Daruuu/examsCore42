#ifndef SEARCHABLE_ARRAY_BAG_HPP
#define SEARCHABLE_ARRAY_BAG_HPP

#include "../array_bag.hpp"
#include "../searchable_bag.hpp"

/*
 * PARTE 1 — searchable_array_bag
 *
 * Herencia múltiple (problema del diamante):
 *
 *           bag<T>  ← virtual
 *          /      \
 *   array_bag   searchable_bag
 *          \      /
 *     searchable_array_bag
 *
 * Solo añades search(): búsqueda lineal en el array interno.
 * add/remove/contains ya vienen de array_bag.
 */

template <typename T>
class searchable_array_bag : public array_bag<T>, public searchable_bag<T> {
public:
	// --- OCF: delega en array_bag ---
	searchable_array_bag() : array_bag<T>() {}

	searchable_array_bag(const searchable_array_bag& other)
		: bag<T>(),
		  array_bag<T>(other),
		  searchable_bag<T>() {}

	searchable_array_bag& operator=(const searchable_array_bag& other) {
		if (this != &other)
			array_bag<T>::operator=(other);
		return *this;
	}

	virtual ~searchable_array_bag() {}

	// --- search: retorna puntero al elemento DENTRO del bag (no copia) ---
	virtual const T* search(const T& item) const {
		const T* items = this->getItems();
		size_t n = this->size();
		for (size_t i = 0; i < n; ++i)
			if (items[i] == item)
				return &items[i];
		return NULL;
	}

	virtual T* search(const T& item) {
		T* items = this->getItems();
		size_t n = this->size();
		for (size_t i = 0; i < n; ++i)
			if (items[i] == item)
				return &items[i];
		return NULL;
	}
};

#endif
