#ifndef SET_HPP
#define SET_HPP

#include "../searchable_bag.hpp"

/*
 * PARTE 2 — set
 *
 * Envuelve (wrap) un searchable_bag* y convierte bag → set.
 *
 * Diferencia clave:
 *   bag.add(x)     → siempre añade (permite duplicados)
 *   set.insert(x)  → solo si NO existe (usa search)
 *
 * Uso en el examen:
 *   set<int> s(new searchable_array_bag<int>());
 *   set<string> s(new searchable_tree_bag<string>());
 */

template <typename T>
class set {
	searchable_bag<T>* bag_;

public:
	// Recibe puntero: el set es dueño (delete en destructor)
	explicit set(searchable_bag<T>* bag) : bag_(bag) {}

	// OCF mínimo (el main del subject no copia sets)
	set(const set& other) : bag_(NULL) { (void)other; }

	set& operator=(const set& other) {
		(void)other;
		return *this;
	}

	~set() { delete bag_; }

	// --- insert: LÓGICA DEL SET en 3 líneas ---
	bool insert(const T& item) {
		if (bag_->search(item) != NULL)  // ya existe
			return false;
		return bag_->add(item);
	}

	// --- resto: delega al bag ---
	bool erase(const T& item) { return bag_->remove(item); }
	bool contains(const T& item) const { return bag_->contains(item); }
	const T* find(const T& item) const { return bag_->search(item); }
	T* find(const T& item) { return bag_->search(item); }
	size_t size() const { return bag_->size(); }
	bool empty() const { return bag_->isEmpty(); }
	void clear() { bag_->clear(); }
};

#endif
