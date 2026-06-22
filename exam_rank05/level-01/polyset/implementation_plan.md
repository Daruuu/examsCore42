# Plan de Implementación: Polyset

Este documento describe la estrategia y el diseño para resolver el problema `Polyset`. El objetivo es añadir capacidades de búsqueda a las colecciones existentes (`array_bag` y `tree_bag`) y luego crear un decorador `set` que garantice la unicidad de los elementos utilizando estas colecciones.

## User Review Required

Por favor, revisa este plan. Una vez que lo apruebes, procederé a crear automáticamente todos los archivos `.hpp` y `.cpp` descritos a continuación en tu directorio.

## Propuesta de Implementación

### 1. `searchable_array_bag`
Heredará de `array_bag` y `searchable_bag`.

*   **Atributos**: Utiliza `data` y `size` heredados de `array_bag`.
*   **Métodos a implementar**:
    *   Forma Canónica Ortodoxa (Constructor por defecto, copia, operador de asignación, destructor). Llama a los de `array_bag`.
    *   `bool has(int value) const`: Un bucle `for` simple que itere desde `0` hasta `size - 1` buscando `value` dentro del array `data`.

#### [NEW] [searchable_array_bag.hpp](file:///home/daruuu/CLionProjects/examsCore42/exam_rank05/level-01/polyset/subject/searchable_array_bag.hpp)
#### [NEW] [searchable_array_bag.cpp](file:///home/daruuu/CLionProjects/examsCore42/exam_rank05/level-01/polyset/subject/searchable_array_bag.cpp)

---

### 2. `searchable_tree_bag`
Heredará de `tree_bag` y `searchable_bag`.

*   **Atributos**: Utiliza `tree` (puntero a `node`) heredado de `tree_bag`.
*   **Métodos a implementar**:
    *   Forma Canónica Ortodoxa.
    *   `bool has(int value) const`: Recorrido de un árbol binario de búsqueda. Si `value` es menor que el valor del nodo actual, busca en el hijo izquierdo (`l`); si es mayor, en el derecho (`r`); si es igual, retorna `true`.

#### [NEW] [searchable_tree_bag.hpp](file:///home/daruuu/CLionProjects/examsCore42/exam_rank05/level-01/polyset/subject/searchable_tree_bag.hpp)
#### [NEW] [searchable_tree_bag.cpp](file:///home/daruuu/CLionProjects/examsCore42/exam_rank05/level-01/polyset/subject/searchable_tree_bag.cpp)

---

### 3. `set`
Un envoltorio (wrapper) para cualquier `searchable_bag`. Modifica el comportamiento de inserción para evitar duplicados.

*   **Atributos**: `searchable_bag* _bag;` (Puntero para permitir la forma canónica, ya que las referencias no se pueden reasignar).
*   **Métodos a implementar**:
    *   Forma Canónica Ortodoxa.
    *   Constructor que acepte `searchable_bag&` (como se ve en `main.c`: `set sa(*a);`).
    *   `void insert(int value)`: Comprueba `if (!_bag->has(value))` antes de llamar a `_bag->insert(value)`.
    *   `void insert(int* arr, int size)`: Itera el array e inserta cada elemento usando la lógica sin duplicados.
    *   `void print() const`: Llama a `_bag->print()`.
    *   `void clear()`: Llama a `_bag->clear()`.
    *   `bool has(int value) const`: Llama a `_bag->has(value)`.
    *   `searchable_bag& get_bag()`: Retorna `*_bag`.

#### [NEW] [set.hpp](file:///home/daruuu/CLionProjects/examsCore42/exam_rank05/level-01/polyset/subject/set.hpp)
#### [NEW] [set.cpp](file:///home/daruuu/CLionProjects/examsCore42/exam_rank05/level-01/polyset/subject/set.cpp)

## Verification Plan

1.  Una vez creados los archivos, compilaré todo usando `c++ -Wall -Wextra -Werror *.cpp main.c`.
2.  Ejecutaré el binario resultante con algunos argumentos numéricos (ej. `./a.out 1 2 3 3 4`) para validar que la salida coincide con el comportamiento esperado:
    *   Las bolsas normales permiten duplicados.
    *   El `set` imprimirá los números sin repetición, validando correctamente el funcionamiento del decorador y de los métodos `has()`.
