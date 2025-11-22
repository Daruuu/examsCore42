#include <iostream>
#include <string>
#include "try01/searchable_array_bag.hpp"
#include "try01/searchable_tree_bag.hpp"
#include "try01/set.hpp"

/*
 * PROGRAMA DE PRUEBA PARA POLYSET
 * 
 * Este programa prueba todas las funcionalidades implementadas:
 * 1. Bags básicos (array_bag y tree_bag)
 * 2. Searchable bags (con funcionalidad de búsqueda)
 * 3. Set (que rechaza duplicados)
 * 
 * Conceptos probados:
 * - Agregar elementos
 * - Eliminar elementos
 * - Buscar elementos
 * - Verificar existencia
 * - Propiedad de unicidad del set
 * - Orthodox Canonical Form (copia, asignación)
 */

// Función auxiliar para imprimir resultados de pruebas
void printTestResult(const std::string& test_name, bool passed) {
	std::cout << "[" << (passed ? "OK" : "FAIL") << "] " << test_name << std::endl;
}

// Función auxiliar para imprimir separador
void printSeparator(const std::string& section_name) {
	std::cout << "\n========== " << section_name << " ==========" << std::endl;
}

/*
 * Test 1: Probar array_bag básico
 */
void testArrayBag() {
	printSeparator("TEST 1: ARRAY_BAG");
	
	array_bag<int> bag;
	
	// Test: bag vacío
	printTestResult("Array bag starts empty", bag.isEmpty());
	printTestResult("Array bag size is 0", bag.size() == 0);
	
	// Test: agregar elementos
	bag.add(10);
	bag.add(20);
	bag.add(30);
	printTestResult("Added 3 elements", bag.size() == 3);
	printTestResult("Bag is not empty", !bag.isEmpty());
	
	// Test: contains
	printTestResult("Contains 20", bag.contains(20));
	printTestResult("Does not contain 99", !bag.contains(99));
	
	// Test: permite duplicados
	bag.add(20);
	printTestResult("Allows duplicates (size = 4)", bag.size() == 4);
	
	// Test: remove
	bag.remove(20);
	printTestResult("Removed one occurrence of 20", bag.size() == 3);
	printTestResult("Still contains 20 (duplicate)", bag.contains(20));
	
	// Test: clear
	bag.clear();
	printTestResult("Clear works", bag.isEmpty());
}

/*
 * Test 2: Probar tree_bag básico
 */
void testTreeBag() {
	printSeparator("TEST 2: TREE_BAG");
	
	tree_bag<int> bag;
	
	// Test: bag vacío
	printTestResult("Tree bag starts empty", bag.isEmpty());
	
	// Test: agregar elementos
	bag.add(50);
	bag.add(30);
	bag.add(70);
	bag.add(20);
	bag.add(40);
	printTestResult("Added 5 elements", bag.size() == 5);
	
	// Test: contains (búsqueda en BST)
	printTestResult("Contains 30", bag.contains(30));
	printTestResult("Contains 70", bag.contains(70));
	printTestResult("Does not contain 100", !bag.contains(100));
	
	// Test: permite duplicados
	bag.add(30);
	printTestResult("Allows duplicates (size = 6)", bag.size() == 6);
	
	// Test: remove
	bag.remove(30);
	printTestResult("Removed one occurrence of 30", bag.size() == 5);
	printTestResult("Still contains 30 (duplicate)", bag.contains(30));
}

/*
 * Test 3: Probar searchable_array_bag
 */
void testSearchableArrayBag() {
	printSeparator("TEST 3: SEARCHABLE_ARRAY_BAG");
	
	searchable_array_bag<std::string> bag;
	
	// Agregar elementos
	bag.add("apple");
	bag.add("banana");
	bag.add("cherry");
	
	// Test: search retorna puntero
	const std::string* found = bag.search("banana");
	printTestResult("Search found 'banana'", found != NULL);
	if (found) {
		printTestResult("Search returned correct value", *found == "banana");
	}
	
	// Test: search retorna NULL si no existe
	const std::string* not_found = bag.search("orange");
	printTestResult("Search returns NULL for non-existent", not_found == NULL);
	
	// Test: search con duplicados
	bag.add("banana");
	found = bag.search("banana");
	printTestResult("Search finds duplicate", found != NULL);
}

/*
 * Test 4: Probar searchable_tree_bag
 */
void testSearchableTreeBag() {
	printSeparator("TEST 4: SEARCHABLE_TREE_BAG");
	
	searchable_tree_bag<int> bag;
	
	// Agregar elementos
	bag.add(100);
	bag.add(50);
	bag.add(150);
	bag.add(25);
	bag.add(75);
	
	// Test: search en BST
	const int* found = bag.search(75);
	printTestResult("Search found 75", found != NULL);
	if (found) {
		printTestResult("Search returned correct value", *found == 75);
	}
	
	// Test: search retorna NULL si no existe
	const int* not_found = bag.search(200);
	printTestResult("Search returns NULL for non-existent", not_found == NULL);
}

/*
 * Test 5: Probar set con array_bag
 */
void testSetWithArrayBag() {
	printSeparator("TEST 5: SET (with array_bag)");
	
	// Crear set con searchable_array_bag
	set<int> my_set(new searchable_array_bag<int>());
	
	// Test: set vacío
	printTestResult("Set starts empty", my_set.empty());
	
	// Test: insertar elementos
	printTestResult("Insert 10 returns true", my_set.insert(10));
	printTestResult("Insert 20 returns true", my_set.insert(20));
	printTestResult("Insert 30 returns true", my_set.insert(30));
	printTestResult("Set size is 3", my_set.size() == 3);
	
	// Test: RECHAZA DUPLICADOS (propiedad clave del set)
	printTestResult("Insert duplicate 20 returns FALSE", !my_set.insert(20));
	printTestResult("Size still 3 (duplicate rejected)", my_set.size() == 3);
	
	// Test: contains
	printTestResult("Contains 20", my_set.contains(20));
	printTestResult("Does not contain 99", !my_set.contains(99));
	
	// Test: find
	const int* found = my_set.find(20);
	printTestResult("Find returns pointer to 20", found != NULL && *found == 20);
	
	// Test: erase
	printTestResult("Erase 20 returns true", my_set.erase(20));
	printTestResult("Size is 2 after erase", my_set.size() == 2);
	printTestResult("Does not contain 20 after erase", !my_set.contains(20));
}

/*
 * Test 6: Probar set con tree_bag
 */
void testSetWithTreeBag() {
	printSeparator("TEST 6: SET (with tree_bag)");
	
	// Crear set con searchable_tree_bag
	set<std::string> my_set(new searchable_tree_bag<std::string>());
	
	// Test: insertar elementos
	printTestResult("Insert 'alpha'", my_set.insert("alpha"));
	printTestResult("Insert 'beta'", my_set.insert("beta"));
	printTestResult("Insert 'gamma'", my_set.insert("gamma"));
	
	// Test: RECHAZA DUPLICADOS
	printTestResult("Reject duplicate 'beta'", !my_set.insert("beta"));
	printTestResult("Size is 3", my_set.size() == 3);
	
	// Test: find
	const std::string* found = my_set.find("beta");
	printTestResult("Find 'beta'", found != NULL && *found == "beta");
	
	// Test: clear
	my_set.clear();
	printTestResult("Clear works", my_set.empty());
}

/*
 * Test 7: Orthodox Canonical Form (OCF)
 */
void testOCF() {
	printSeparator("TEST 7: ORTHODOX CANONICAL FORM");
	
	// Test: Copy constructor de array_bag
	array_bag<int> bag1;
	bag1.add(1);
	bag1.add(2);
	bag1.add(3);
	
	array_bag<int> bag2(bag1);  // Copy constructor
	printTestResult("Copy constructor copies size", bag2.size() == 3);
	printTestResult("Copy constructor copies content", bag2.contains(2));
	
	// Test: Assignment operator
	array_bag<int> bag3;
	bag3 = bag1;  // Assignment
	printTestResult("Assignment copies size", bag3.size() == 3);
	printTestResult("Assignment copies content", bag3.contains(2));
	
	// Test: Modificar copia no afecta original
	bag2.add(99);
	printTestResult("Modifying copy doesn't affect original", 
	                bag1.size() == 3 && bag2.size() == 4);
}

/*
 * MAIN - Ejecuta todas las pruebas
 */
int main() {
	std::cout << "\n";
	std::cout << "╔════════════════════════════════════════════╗\n";
	std::cout << "║   POLYSET - PROGRAMA DE PRUEBA COMPLETO   ║\n";
	std::cout << "║         C++98 Implementation               ║\n";
	std::cout << "╚════════════════════════════════════════════╝\n";
	
	testArrayBag();
	testTreeBag();
	testSearchableArrayBag();
	testSearchableTreeBag();
	testSetWithArrayBag();
	testSetWithTreeBag();
	testOCF();
	
	printSeparator("ALL TESTS COMPLETED");
	std::cout << "\nSi todos los tests muestran [OK], la implementación es correcta!\n\n";
	
	return 0;
}
