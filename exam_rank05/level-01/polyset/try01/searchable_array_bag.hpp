#ifndef SEARCHABLE_ARRAY_BAG_HPP
#define SEARCHABLE_ARRAY_BAG_HPP

#include "../array_bag.hpp"
#include "../searchable_bag.hpp"

/*
 * SEARCHABLE_ARRAY_BAG - Bag con array y capacidad de búsqueda
 * 
 * Esta clase combina:
 * - array_bag: implementación con array dinámico
 * - searchable_bag: interfaz de búsqueda
 * 
 * HERENCIA MÚLTIPLE:
 * Hereda de ambas clases usando herencia virtual para evitar
 * el problema del "diamante" (diamond problem).
 * 
 * Diagrama de herencia:
 *           bag<T> (virtual)
 *          /              \
 *   array_bag<T>    searchable_bag<T>
 *          \              /
 *      searchable_array_bag<T>
 * 
 * La palabra clave "virtual" en la herencia de bag<T> asegura
 * que solo haya una instancia de bag<T> en la jerarquía.
 * 
 * Orthodox Canonical Form (OCF):
 * - Constructor por defecto
 * - Copy constructor
 * - Operador de asignación
 * - Destructor
 */

template <typename T>
class searchable_array_bag : public array_bag<T>, public searchable_bag<T> {
public:
	// ========== ORTHODOX CANONICAL FORM ==========
	
	/*
	 * Constructor por defecto
	 * Llama al constructor de array_bag
	 */
	searchable_array_bag() : array_bag<T>() {}
	
	/*
	 * Copy constructor
	 * Copia el array_bag subyacente
	 */
	searchable_array_bag(const searchable_array_bag& other) 
		: bag<T>(),  // Constructor de la base virtual
		  array_bag<T>(other),
		  searchable_bag<T>() {}
	
	/*
	 * Operador de asignación
	 * Delega a array_bag
	 */
	searchable_array_bag& operator=(const searchable_array_bag& other) {
		if (this != &other) {
			array_bag<T>::operator=(other);
		}
		return *this;
	}
	
	/*
	 * Destructor
	 * El destructor de array_bag se encarga de liberar memoria
	 */
	virtual ~searchable_array_bag() {}
	
	// ========== IMPLEMENTACIÓN DE SEARCH ==========
	
	/*
	 * search (versión const) - Busca un elemento y retorna puntero a él
	 * @param item: elemento a buscar
	 * @return: puntero const al elemento si existe, NULL si no
	 * 
	 * Implementación: búsqueda lineal en el array
	 * Complejidad: O(n)
	 * 
	 * IMPORTANTE: Retorna un puntero al elemento DENTRO del array,
	 * no una copia. Esto permite acceder al elemento sin copiarlo.
	 */
	virtual const T* search(const T& item) const {
		// Obtener acceso al array interno
		const T* items = this->getItems();
		size_t count = this->size();
		
		// Búsqueda lineal
		for (size_t i = 0; i < count; ++i) {
			if (items[i] == item) {
				return &items[i];  // Retornar puntero al elemento encontrado
			}
		}
		
		return NULL;  // No encontrado
	}
	
	/*
	 * search (versión no-const) - Busca un elemento y retorna puntero modificable
	 * @param item: elemento a buscar
	 * @return: puntero al elemento si existe, NULL si no
	 * 
	 * Permite modificar el elemento encontrado
	 */
	virtual T* search(const T& item) {
		// Obtener acceso al array interno
		T* items = this->getItems();
		size_t count = this->size();
		
		// Búsqueda lineal
		for (size_t i = 0; i < count; ++i) {
			if (items[i] == item) {
				return &items[i];  // Retornar puntero al elemento encontrado
			}
		}
		
		return NULL;  // No encontrado
	}
};

#endif // SEARCHABLE_ARRAY_BAG_HPP
