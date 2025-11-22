#ifndef SEARCHABLE_BAG_HPP
#define SEARCHABLE_BAG_HPP

#include "bag.hpp"

/*
 * SEARCHABLE_BAG - Interfaz para bags con capacidad de búsqueda
 * 
 * Extiende el concepto de bag agregando funcionalidad de búsqueda.
 * Esta es una clase abstracta que define la interfaz para buscar
 * elementos en el bag.
 * 
 * Hereda de bag<T> para mantener todas las operaciones básicas
 * y agrega el método search() para búsqueda avanzada.
 * 
 * Implementaciones concretas: searchable_array_bag, searchable_tree_bag
 */

template <typename T>
class searchable_bag : public virtual bag<T> {
public:
	// ========== ORTHODOX CANONICAL FORM ==========
	
	/*
	 * Destructor virtual
	 * Permite la destrucción correcta de objetos derivados
	 */
	virtual ~searchable_bag() {}
	
	// ========== OPERACIÓN DE BÚSQUEDA ==========
	
	/*
	 * search - Busca un elemento en el bag y retorna un puntero a él
	 * @param item: elemento a buscar
	 * @return: puntero al elemento si se encuentra, NULL si no existe
	 * 
	 * Método const: no modifica el estado del objeto
	 * 
	 * IMPORTANTE: Retorna un puntero al elemento DENTRO del bag,
	 * no una copia. Esto permite inspeccionar el elemento sin copiarlo.
	 * 
	 * Diferencia con contains():
	 * - contains() solo dice si existe (true/false)
	 * - search() retorna un puntero al elemento encontrado
	 */
	virtual const T* search(const T& item) const = 0;
	
	/*
	 * search (versión no-const)
	 * Permite modificar el elemento encontrado
	 * @param item: elemento a buscar
	 * @return: puntero al elemento si se encuentra, NULL si no existe
	 */
	virtual T* search(const T& item) = 0;

protected:
	/*
	 * Constructor protegido
	 * Evita la instanciación directa de la clase abstracta
	 */
	searchable_bag() {}
	
	/*
	 * Copy constructor protegido
	 */
	searchable_bag(const searchable_bag& other) : bag<T>(other) {}
	
	/*
	 * Operador de asignación protegido
	 */
	searchable_bag& operator=(const searchable_bag& other) {
		if (this != &other) {
			bag<T>::operator=(other);
		}
		return *this;
	}
};

#endif // SEARCHABLE_BAG_HPP
