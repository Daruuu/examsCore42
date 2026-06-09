#ifndef SEARCHABLE_TREE_BAG_HPP
#define SEARCHABLE_TREE_BAG_HPP

#include "../tree_bag.hpp"
#include "../searchable_bag.hpp"

/*
 * PARTE 1 — searchable_tree_bag
 *
 * Misma idea que searchable_array_bag, pero con tree_bag (BST).
 * search() recorre el árbol: O(log n) promedio.
 */

template <typename T>
class searchable_tree_bag : public tree_bag<T>, public searchable_bag<T> {
	typedef typename tree_bag<T>::Node Node;

	// Búsqueda recursiva en el BST (const)
	const Node* find_node(const Node* node, const T& item) const {
		if (!node || node->data == item)
			return node;
		if (item < node->data)
			return find_node(node->left, item);
		return find_node(node->right, item);
	}

	// Versión no-const
	Node* find_node(Node* node, const T& item) {
		if (!node || node->data == item)
			return node;
		if (item < node->data)
			return find_node(node->left, item);
		return find_node(node->right, item);
	}

public:
	searchable_tree_bag() : tree_bag<T>() {}

	searchable_tree_bag(const searchable_tree_bag& other)
		: bag<T>(),
		  tree_bag<T>(other),
		  searchable_bag<T>() {}

	searchable_tree_bag& operator=(const searchable_tree_bag& other) {
		if (this != &other)
			tree_bag<T>::operator=(other);
		return *this;
	}

	virtual ~searchable_tree_bag() {}

	virtual const T* search(const T& item) const {
		const Node* found = find_node(this->getRoot(), item);
		return found ? &found->data : NULL;
	}

	virtual T* search(const T& item) {
		Node* found = find_node(this->getRoot(), item);
		return found ? &found->data : NULL;
	}
};

#endif
