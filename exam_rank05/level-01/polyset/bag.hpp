#ifndef BAG_HPP
#define BAG_HPP

#include <cstddef> // Para size_t en C++98

/*
 * BAG (Bolsa) - Clase abstracta base
 * 
 * Un "bag" es una colección que:
 * - Permite elementos duplicados
 * - No mantiene un orden específico
 * - Permite agregar, eliminar y consultar elementos
 * 
 * Esta es una clase abstracta (interfaz) que define las operaciones
 * básicas que cualquier implementación de bag debe proporcionar.
 * 
 * Implementaciones concretas: array_bag, tree_bag
 */

template <typename T>
class bag {
public:
	// ========== ORTHODOX CANONICAL FORM ==========
	
	/*
	 * Destructor virtual
	 * IMPORTANTE: Debe ser virtual para permitir polimorfismo correcto.
	 * Cuando se elimina un objeto derivado a través de un puntero base,
	 * se llama al destructor correcto de la clase derivada.
	 */
	virtual ~bag() {}
	
	// ========== OPERACIONES PRINCIPALES ==========
	
	/*
	 * add - Agrega un elemento al bag
	 * @param item: elemento a agregar
	 * @return: true si se agregó exitosamente, false en caso contrario
	 * 
	 * Nota: Los bags permiten duplicados, así que normalmente siempre
	 * retorna true a menos que haya un error (ej: memoria llena)
	 */
	virtual bool add(const T& item) = 0;
	
	/*
	 * remove - Elimina una ocurrencia de un elemento del bag
	 * @param item: elemento a eliminar
	 * @return: true si se encontró y eliminó, false si no existe
	 * 
	 * Nota: Si hay duplicados, solo elimina UNA ocurrencia
	 */
	virtual bool remove(const T& item) = 0;
	
	/*
	 * contains - Verifica si un elemento existe en el bag
	 * @param item: elemento a buscar
	 * @return: true si existe, false en caso contrario
	 * 
	 * Método const: no modifica el estado del objeto
	 */
	virtual bool contains(const T& item) const = 0;
	
	/*
	 * size - Retorna el número de elementos en el bag
	 * @return: cantidad de elementos (incluyendo duplicados)
	 * 
	 * Método const: no modifica el estado del objeto
	 */
	virtual size_t size() const = 0;
	
	/*
	 * isEmpty - Verifica si el bag está vacío
	 * @return: true si no hay elementos, false en caso contrario
	 * 
	 * Método const: no modifica el estado del objeto
	 */
	virtual bool isEmpty() const = 0;
	
	/*
	 * clear - Elimina todos los elementos del bag
	 * Deja el bag en estado vacío
	 */
	virtual void clear() = 0;

protected:
	/*
	 * Constructor protegido
	 * Evita la instanciación directa de la clase abstracta.
	 * Solo las clases derivadas pueden llamar a este constructor.
	 */
	bag() {}
	
	/*
	 * Copy constructor protegido
	 * Las clases derivadas deben implementar su propia copia
	 */
	bag(const bag& other) { (void)other; }
	
	/*
	 * Operador de asignación protegido
	 * Las clases derivadas deben implementar su propia asignación
	 */
	bag& operator=(const bag& other) { (void)other; return *this; }
};

#endif // BAG_HPP
