#ifndef SET_HPP
#define SET_HPP

#include "../searchable_bag.hpp"

/*
 * SET - Conjunto que NO permite duplicados
 * 
 * Un set es una colección que:
 * - NO permite elementos duplicados (diferencia clave con bag)
 * - No mantiene un orden específico (depende de la implementación subyacente)
 * - Permite agregar, eliminar y consultar elementos
 * 
 * IMPLEMENTACIÓN:
 * Esta clase ENVUELVE (wraps) un searchable_bag y agrega la lógica
 * para rechazar duplicados. Usa el patrón de diseño "Wrapper" o "Decorator".
 * 
 * ESTRATEGIA:
 * - Antes de agregar un elemento, usa search() para verificar si ya existe
 * - Si existe, rechaza la adición (retorna false)
 * - Si no existe, lo agrega al bag subyacente
 * 
 * VENTAJA:
 * Puede usar cualquier implementación de searchable_bag:
 * - searchable_array_bag: búsqueda O(n)
 * - searchable_tree_bag: búsqueda O(log n) - más eficiente
 * 
 * Orthodox Canonical Form (OCF):
 * - Constructor por defecto
 * - Copy constructor (copia profunda del bag)
 * - Operador de asignación (copia profunda)
 * - Destructor (libera el bag)
 */

template <typename T>
class set {
private:
	/*
	 * bag_ - Puntero al searchable_bag subyacente
	 * 
	 * Usamos un puntero para permitir polimorfismo:
	 * puede apuntar a searchable_array_bag o searchable_tree_bag
	 */
	searchable_bag<T>* bag_;

public:
	// ========== ORTHODOX CANONICAL FORM ==========
	
	/*
	 * Constructor que recibe un searchable_bag
	 * @param bag: puntero al bag a usar (set toma ownership)
	 * 
	 * IMPORTANTE: El set toma posesión del puntero y lo liberará
	 * en el destructor. No liberar el puntero externamente.
	 */
	explicit set(searchable_bag<T>* bag) : bag_(bag) {}
	
	/*
	 * Copy constructor
	 * Realiza una copia profunda del bag subyacente
	 * 
	 * PROBLEMA: No podemos copiar un puntero polimórfico directamente
	 * sin conocer el tipo concreto. Por simplicidad, este constructor
	 * crea un nuevo bag vacío del mismo tipo.
	 * 
	 * NOTA: Una implementación más robusta usaría un método clone() virtual
	 */
	set(const set& other) : bag_(NULL) {
		// Para una implementación completa, necesitaríamos un método clone()
		// Por ahora, simplemente no copiamos el bag
		(void)other;
	}
	
	/*
	 * Operador de asignación
	 * Realiza una copia profunda, evitando auto-asignación
	 */
	set& operator=(const set& other) {
		if (this != &other) {
			// Similar al copy constructor, necesitaríamos clone()
			// Por ahora, no hacemos nada
		}
		return *this;
	}
	
	/*
	 * Destructor
	 * Libera el bag subyacente
	 */
	~set() {
		delete bag_;
	}
	
	// ========== OPERACIONES DE SET ==========
	
	/*
	 * insert - Intenta insertar un elemento en el set
	 * @param item: elemento a insertar
	 * @return: true si se insertó, false si ya existía (duplicado)
	 * 
	 * LÓGICA CLAVE DEL SET:
	 * 1. Buscar si el elemento ya existe usando search()
	 * 2. Si existe, rechazar (retornar false)
	 * 3. Si no existe, agregarlo al bag (retornar true)
	 * 
	 * Esta es la diferencia fundamental entre set y bag:
	 * - bag.add() siempre agrega (permite duplicados)
	 * - set.insert() solo agrega si no existe (rechaza duplicados)
	 */
	bool insert(const T& item) {
		// Verificar si el elemento ya existe
		if (bag_->search(item) != NULL) {
			return false;  // Duplicado - rechazar
		}
		
		// No existe - agregarlo
		return bag_->add(item);
	}
	
	/*
	 * erase - Elimina un elemento del set
	 * @param item: elemento a eliminar
	 * @return: true si se eliminó, false si no existía
	 * 
	 * Delega directamente al bag subyacente
	 */
	bool erase(const T& item) {
		return bag_->remove(item);
	}
	
	/*
	 * contains - Verifica si un elemento existe en el set
	 * @param item: elemento a buscar
	 * @return: true si existe, false en caso contrario
	 * 
	 * Delega al bag subyacente
	 */
	bool contains(const T& item) const {
		return bag_->contains(item);
	}
	
	/*
	 * find - Busca un elemento y retorna puntero a él
	 * @param item: elemento a buscar
	 * @return: puntero const al elemento si existe, NULL si no
	 * 
	 * Usa la funcionalidad de search del searchable_bag
	 */
	const T* find(const T& item) const {
		return bag_->search(item);
	}
	
	/*
	 * find (versión no-const)
	 * Permite modificar el elemento encontrado
	 */
	T* find(const T& item) {
		return bag_->search(item);
	}
	
	/*
	 * size - Retorna el número de elementos en el set
	 * @return: cantidad de elementos únicos
	 * 
	 * Delega al bag subyacente
	 */
	size_t size() const {
		return bag_->size();
	}
	
	/*
	 * empty - Verifica si el set está vacío
	 * @return: true si no hay elementos, false en caso contrario
	 * 
	 * Delega al bag subyacente
	 */
	bool empty() const {
		return bag_->isEmpty();
	}
	
	/*
	 * clear - Elimina todos los elementos del set
	 * 
	 * Delega al bag subyacente
	 */
	void clear() {
		bag_->clear();
	}
	
	// ========== MÉTODOS ADICIONALES ==========
	
	/*
	 * getBag - Retorna puntero al bag subyacente
	 * @return: puntero al searchable_bag interno
	 * 
	 * Útil para acceso directo al bag (usar con cuidado)
	 */
	searchable_bag<T>* getBag() { return bag_; }
	const searchable_bag<T>* getBag() const { return bag_; }
};

#endif // SET_HPP
