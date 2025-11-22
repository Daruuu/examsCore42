#ifndef SEARCHABLE_TREE_BAG_HPP
#define SEARCHABLE_TREE_BAG_HPP

#include "../tree_bag.hpp"
#include "../searchable_bag.hpp"

/*
 * SEARCHABLE_TREE_BAG - Bag con BST y capacidad de búsqueda
 * 
 * Esta clase combina:
 * - tree_bag: implementación con árbol binario de búsqueda
 * - searchable_bag: interfaz de búsqueda
 * 
 * HERENCIA MÚLTIPLE:
 * Hereda de ambas clases usando herencia virtual para evitar
 * el problema del "diamante" (diamond problem).
 * 
 * Diagrama de herencia:
 *           bag<T> (virtual)
 *          /              \
 *   tree_bag<T>     searchable_bag<T>
 *          \              /
 *      searchable_tree_bag<T>
 * 
 * VENTAJA DEL BST:
 * La búsqueda es más eficiente que en array_bag:
 * - Array: O(n) búsqueda lineal
 * - BST: O(log n) promedio, O(n) peor caso
 * 
 * Orthodox Canonical Form (OCF):
 * - Constructor por defecto
 * - Copy constructor
 * - Operador de asignación
 * - Destructor
 */

template <typename T>
class searchable_tree_bag : public tree_bag<T>, public searchable_bag<T> {
private:
	/*
	 * Tipo de nodo heredado de tree_bag
	 * Necesitamos acceso a la estructura Node
	 */
	typedef typename tree_bag<T>::Node Node;
	
	/*
	 * searchInTree - Búsqueda recursiva en el BST
	 * @param node: raíz del subárbol actual
	 * @param item: elemento a buscar
	 * @return: puntero al nodo que contiene el elemento, NULL si no existe
	 * 
	 * Aprovecha la estructura del BST para búsqueda eficiente
	 */
	const Node* searchInTree(const Node* node, const T& item) const {
		// Caso base: árbol vacío o elemento encontrado
		if (node == NULL || node->data == item) {
			return node;
		}
		
		// Buscar en subárbol izquierdo o derecho
		if (item < node->data) {
			return searchInTree(node->left, item);
		} else {
			return searchInTree(node->right, item);
		}
	}
	
	/*
	 * searchInTree (versión no-const)
	 * Permite modificar el nodo encontrado
	 */
	Node* searchInTree(Node* node, const T& item) {
		// Caso base: árbol vacío o elemento encontrado
		if (node == NULL || node->data == item) {
			return node;
		}
		
		// Buscar en subárbol izquierdo o derecho
		if (item < node->data) {
			return searchInTree(node->left, item);
		} else {
			return searchInTree(node->right, item);
		}
	}

public:
	// ========== ORTHODOX CANONICAL FORM ==========
	
	/*
	 * Constructor por defecto
	 * Llama al constructor de tree_bag
	 */
	searchable_tree_bag() : tree_bag<T>() {}
	
	/*
	 * Copy constructor
	 * Copia el tree_bag subyacente
	 */
	searchable_tree_bag(const searchable_tree_bag& other) 
		: bag<T>(),  // Constructor de la base virtual
		  tree_bag<T>(other),
		  searchable_bag<T>() {}
	
	/*
	 * Operador de asignación
	 * Delega a tree_bag
	 */
	searchable_tree_bag& operator=(const searchable_tree_bag& other) {
		if (this != &other) {
			tree_bag<T>::operator=(other);
		}
		return *this;
	}
	
	/*
	 * Destructor
	 * El destructor de tree_bag se encarga de liberar el árbol
	 */
	virtual ~searchable_tree_bag() {}
	
	// ========== IMPLEMENTACIÓN DE SEARCH ==========
	
	/*
	 * search (versión const) - Busca un elemento y retorna puntero a él
	 * @param item: elemento a buscar
	 * @return: puntero const al elemento si existe, NULL si no
	 * 
	 * Implementación: búsqueda en BST
	 * Complejidad: O(log n) promedio, O(n) peor caso
	 * 
	 * VENTAJA: Más rápido que búsqueda lineal en array
	 */
	virtual const T* search(const T& item) const {
		// Buscar el nodo en el árbol
		const Node* found = searchInTree(this->getRoot(), item);
		
		// Si se encontró, retornar puntero al dato
		if (found != NULL) {
			return &(found->data);
		}
		
		return NULL;  // No encontrado
	}
	
	/*
	 * search (versión no-const) - Busca un elemento y retorna puntero modificable
	 * @param item: elemento a buscar
	 * @return: puntero al elemento si existe, NULL si no
	 * 
	 * Permite modificar el elemento encontrado
	 * ADVERTENCIA: Modificar el valor puede romper la propiedad del BST
	 */
	virtual T* search(const T& item) {
		// Buscar el nodo en el árbol
		Node* found = searchInTree(this->getRoot(), item);
		
		// Si se encontró, retornar puntero al dato
		if (found != NULL) {
			return &(found->data);
		}
		
		return NULL;  // No encontrado
	}
};

#endif // SEARCHABLE_TREE_BAG_HPP
