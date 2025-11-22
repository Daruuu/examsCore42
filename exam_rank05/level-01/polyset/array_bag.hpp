#ifndef ARRAY_BAG_HPP
#define ARRAY_BAG_HPP

#include "bag.hpp"
#include <algorithm> // Para std::find, std::copy en C++98

/*
 * ARRAY_BAG - Implementación de bag usando un array dinámico
 * 
 * Características:
 * - Usa un array dinámico (puntero + capacidad)
 * - Crece automáticamente cuando se llena
 * - Operaciones:
 *   * add: O(1) amortizado (puede requerir redimensionar)
 *   * remove: O(n) - búsqueda lineal + desplazamiento
 *   * contains: O(n) - búsqueda lineal
 *   * size: O(1)
 * 
 * Orthodox Canonical Form (OCF):
 * - Constructor por defecto
 * - Copy constructor (copia profunda)
 * - Operador de asignación (copia profunda)
 * - Destructor (libera memoria)
 */

template <typename T>
class array_bag : public virtual bag<T> {
protected:
	T* items_;           // Array dinámico de elementos
	size_t item_count_;  // Número actual de elementos
	size_t capacity_;    // Capacidad total del array
	
	static const size_t DEFAULT_CAPACITY = 10;
	
	/*
	 * resize - Redimensiona el array interno
	 * @param new_capacity: nueva capacidad del array
	 * 
	 * Crea un nuevo array más grande y copia los elementos existentes.
	 * Libera el array antiguo.
	 */
	void resize(size_t new_capacity) {
		// Crear nuevo array
		T* new_items = new T[new_capacity];
		
		// Copiar elementos existentes
		for (size_t i = 0; i < item_count_; ++i) {
			new_items[i] = items_[i];
		}
		
		// Liberar array antiguo
		delete[] items_;
		
		// Actualizar puntero y capacidad
		items_ = new_items;
		capacity_ = new_capacity;
	}

public:
	// ========== ORTHODOX CANONICAL FORM ==========
	
	/*
	 * Constructor por defecto
	 * Crea un bag vacío con capacidad inicial
	 */
	array_bag() : items_(new T[DEFAULT_CAPACITY]), 
	              item_count_(0), 
	              capacity_(DEFAULT_CAPACITY) {}
	
	/*
	 * Copy constructor
	 * Realiza una copia profunda del bag
	 */
	array_bag(const array_bag& other) 
		: bag<T>(),  // Inicializar base virtual explícitamente
		  items_(new T[other.capacity_]),
		  item_count_(other.item_count_),
		  capacity_(other.capacity_) {
		// Copiar todos los elementos
		for (size_t i = 0; i < item_count_; ++i) {
			items_[i] = other.items_[i];
		}
	}
	
	/*
	 * Operador de asignación
	 * Realiza una copia profunda, evitando auto-asignación
	 */
	array_bag& operator=(const array_bag& other) {
		if (this != &other) {
			// Liberar recursos actuales
			delete[] items_;
			
			// Copiar datos del otro bag
			capacity_ = other.capacity_;
			item_count_ = other.item_count_;
			items_ = new T[capacity_];
			
			for (size_t i = 0; i < item_count_; ++i) {
				items_[i] = other.items_[i];
			}
		}
		return *this;
	}
	
	/*
	 * Destructor
	 * Libera la memoria del array dinámico
	 */
	virtual ~array_bag() {
		delete[] items_;
	}
	
	// ========== IMPLEMENTACIÓN DE OPERACIONES DE BAG ==========
	
	/*
	 * add - Agrega un elemento al final del array
	 * Si el array está lleno, lo redimensiona (duplica capacidad)
	 */
	virtual bool add(const T& item) {
		// Si el array está lleno, redimensionar
		if (item_count_ >= capacity_) {
			resize(capacity_ * 2);
		}
		
		// Agregar elemento al final
		items_[item_count_] = item;
		++item_count_;
		
		return true;
	}
	
	/*
	 * remove - Elimina la primera ocurrencia del elemento
	 * Busca linealmente y desplaza elementos para llenar el hueco
	 */
	virtual bool remove(const T& item) {
		// Buscar el elemento
		for (size_t i = 0; i < item_count_; ++i) {
			if (items_[i] == item) {
				// Desplazar elementos hacia la izquierda
				for (size_t j = i; j < item_count_ - 1; ++j) {
					items_[j] = items_[j + 1];
				}
				--item_count_;
				return true;
			}
		}
		return false; // No se encontró el elemento
	}
	
	/*
	 * contains - Verifica si el elemento existe
	 * Búsqueda lineal O(n)
	 */
	virtual bool contains(const T& item) const {
		for (size_t i = 0; i < item_count_; ++i) {
			if (items_[i] == item) {
				return true;
			}
		}
		return false;
	}
	
	/*
	 * size - Retorna el número de elementos
	 */
	virtual size_t size() const {
		return item_count_;
	}
	
	/*
	 * isEmpty - Verifica si el bag está vacío
	 */
	virtual bool isEmpty() const {
		return item_count_ == 0;
	}
	
	/*
	 * clear - Elimina todos los elementos
	 * No libera memoria, solo resetea el contador
	 */
	virtual void clear() {
		item_count_ = 0;
	}
	
	// ========== MÉTODOS DE ACCESO PROTEGIDOS ==========
	
	/*
	 * getItems - Retorna puntero al array interno
	 * Útil para clases derivadas que necesitan acceso directo
	 */
	T* getItems() { return items_; }
	const T* getItems() const { return items_; }
};

#endif // ARRAY_BAG_HPP
