#ifndef TREE_BAG_HPP
#define TREE_BAG_HPP

#include "bag.hpp"

/*
 * TREE_BAG - Implementación de bag usando un árbol binario de búsqueda (BST)
 * 
 * Características:
 * - Usa un BST que PERMITE duplicados
 * - Los duplicados se almacenan en el subárbol derecho
 * - Operaciones:
 *   * add: O(log n) promedio, O(n) peor caso
 *   * remove: O(log n) promedio, O(n) peor caso
 *   * contains: O(log n) promedio, O(n) peor caso
 *   * size: O(1) - se mantiene un contador
 * 
 * Orthodox Canonical Form (OCF):
 * - Constructor por defecto
 * - Copy constructor (copia profunda del árbol)
 * - Operador de asignación (copia profunda)
 * - Destructor (libera todos los nodos)
 */

template <typename T>
class tree_bag : public virtual bag<T> {
protected:
	/*
	 * Estructura de nodo del BST
	 * Cada nodo contiene:
	 * - data: el valor almacenado
	 * - left: puntero al hijo izquierdo (valores menores)
	 * - right: puntero al hijo derecho (valores mayores o iguales)
	 */
	struct Node {
		T data;
		Node* left;
		Node* right;
		
		// Constructor del nodo
		Node(const T& value) : data(value), left(NULL), right(NULL) {}
	};
	
	Node* root_;         // Raíz del árbol
	size_t item_count_;  // Número total de elementos
	
	// ========== MÉTODOS AUXILIARES RECURSIVOS ==========
	
	/*
	 * copyTree - Copia recursivamente un árbol
	 * @param node: nodo raíz del árbol a copiar
	 * @return: puntero a la raíz del nuevo árbol copiado
	 * 
	 * Realiza un recorrido preorden para copiar todos los nodos
	 */
	Node* copyTree(Node* node) {
		if (node == NULL) {
			return NULL;
		}
		
		// Crear nuevo nodo con el mismo valor
		Node* new_node = new Node(node->data);
		
		// Copiar recursivamente subárboles
		new_node->left = copyTree(node->left);
		new_node->right = copyTree(node->right);
		
		return new_node;
	}
	
	/*
	 * destroyTree - Libera recursivamente todos los nodos del árbol
	 * @param node: nodo raíz del árbol a destruir
	 * 
	 * Usa recorrido postorden para liberar primero los hijos
	 */
	void destroyTree(Node* node) {
		if (node != NULL) {
			destroyTree(node->left);
			destroyTree(node->right);
			delete node;
		}
	}
	
	/*
	 * insertNode - Inserta un elemento en el BST (permite duplicados)
	 * @param node: raíz del subárbol actual
	 * @param item: elemento a insertar
	 * @return: puntero a la raíz del subárbol modificado
	 * 
	 * Regla: duplicados van al subárbol derecho (>=)
	 */
	Node* insertNode(Node* node, const T& item) {
		// Caso base: posición encontrada
		if (node == NULL) {
			return new Node(item);
		}
		
		// Insertar en subárbol izquierdo o derecho
		if (item < node->data) {
			node->left = insertNode(node->left, item);
		} else {
			// item >= node->data (permite duplicados)
			node->right = insertNode(node->right, item);
		}
		
		return node;
	}
	
	/*
	 * searchNode - Busca un elemento en el BST
	 * @param node: raíz del subárbol actual
	 * @param item: elemento a buscar
	 * @return: puntero al nodo que contiene el elemento, NULL si no existe
	 */
	Node* searchNode(Node* node, const T& item) const {
		if (node == NULL || node->data == item) {
			return node;
		}
		
		if (item < node->data) {
			return searchNode(node->left, item);
		} else {
			return searchNode(node->right, item);
		}
	}
	
	/*
	 * findMin - Encuentra el nodo con el valor mínimo en un subárbol
	 * @param node: raíz del subárbol
	 * @return: puntero al nodo con valor mínimo
	 * 
	 * El mínimo está siempre en el nodo más a la izquierda
	 */
	Node* findMin(Node* node) const {
		while (node != NULL && node->left != NULL) {
			node = node->left;
		}
		return node;
	}
	
	/*
	 * removeNode - Elimina un elemento del BST
	 * @param node: raíz del subárbol actual
	 * @param item: elemento a eliminar
	 * @param removed: referencia a bool que indica si se eliminó
	 * @return: puntero a la raíz del subárbol modificado
	 * 
	 * Casos:
	 * 1. Nodo hoja: simplemente eliminar
	 * 2. Nodo con un hijo: reemplazar por el hijo
	 * 3. Nodo con dos hijos: reemplazar por sucesor inorden (mínimo del subárbol derecho)
	 */
	Node* removeNode(Node* node, const T& item, bool& removed) {
		if (node == NULL) {
			removed = false;
			return NULL;
		}
		
		if (item < node->data) {
			node->left = removeNode(node->left, item, removed);
		} else if (item > node->data) {
			node->right = removeNode(node->right, item, removed);
		} else {
			// Nodo encontrado
			removed = true;
			
			// Caso 1: Nodo hoja o con un solo hijo
			if (node->left == NULL) {
				Node* temp = node->right;
				delete node;
				return temp;
			} else if (node->right == NULL) {
				Node* temp = node->left;
				delete node;
				return temp;
			}
			
			// Caso 2: Nodo con dos hijos
			// Encontrar sucesor inorden (mínimo del subárbol derecho)
			Node* successor = findMin(node->right);
			
			// Copiar valor del sucesor al nodo actual
			node->data = successor->data;
			
			// Eliminar el sucesor
			bool dummy;
			node->right = removeNode(node->right, successor->data, dummy);
		}
		
		return node;
	}

public:
	// ========== ORTHODOX CANONICAL FORM ==========
	
	/*
	 * Constructor por defecto
	 * Crea un árbol vacío
	 */
	tree_bag() : root_(NULL), item_count_(0) {}
	
	/*
	 * Copy constructor
	 * Realiza una copia profunda del árbol
	 */
	tree_bag(const tree_bag& other) 
		: root_(copyTree(other.root_)), 
		  item_count_(other.item_count_) {}
	
	/*
	 * Operador de asignación
	 * Realiza una copia profunda, evitando auto-asignación
	 */
	tree_bag& operator=(const tree_bag& other) {
		if (this != &other) {
			// Liberar árbol actual
			destroyTree(root_);
			
			// Copiar nuevo árbol
			root_ = copyTree(other.root_);
			item_count_ = other.item_count_;
		}
		return *this;
	}
	
	/*
	 * Destructor
	 * Libera todos los nodos del árbol
	 */
	virtual ~tree_bag() {
		destroyTree(root_);
	}
	
	// ========== IMPLEMENTACIÓN DE OPERACIONES DE BAG ==========
	
	/*
	 * add - Inserta un elemento en el BST
	 */
	virtual bool add(const T& item) {
		root_ = insertNode(root_, item);
		++item_count_;
		return true;
	}
	
	/*
	 * remove - Elimina la primera ocurrencia del elemento
	 */
	virtual bool remove(const T& item) {
		bool removed = false;
		root_ = removeNode(root_, item, removed);
		if (removed) {
			--item_count_;
		}
		return removed;
	}
	
	/*
	 * contains - Verifica si el elemento existe en el árbol
	 */
	virtual bool contains(const T& item) const {
		return searchNode(root_, item) != NULL;
	}
	
	/*
	 * size - Retorna el número de elementos
	 */
	virtual size_t size() const {
		return item_count_;
	}
	
	/*
	 * isEmpty - Verifica si el árbol está vacío
	 */
	virtual bool isEmpty() const {
		return root_ == NULL;
	}
	
	/*
	 * clear - Elimina todos los elementos del árbol
	 */
	virtual void clear() {
		destroyTree(root_);
		root_ = NULL;
		item_count_ = 0;
	}
	
	// ========== MÉTODOS DE ACCESO PROTEGIDOS ==========
	
	/*
	 * getRoot - Retorna puntero a la raíz
	 * Útil para clases derivadas
	 */
	Node* getRoot() { return root_; }
	const Node* getRoot() const { return root_; }
};

#endif // TREE_BAG_HPP
