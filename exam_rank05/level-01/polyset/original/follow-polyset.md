# Polyset — guía para el examen

Solución comentada en esta carpeta (`original/`). Las clases base están en `../`.

---

## Diagramas de clases (Mermaid)

### ANTES — lo que te dan al empezar el examen

En el subject ya existen las **interfaces** y dos **bags concretos**, pero faltan las clases que unen búsqueda + implementación, y el `set`.

```mermaid
classDiagram
    direction TB

    class bag {
        <<abstract>>
        +add(item) bool*
        +remove(item) bool*
        +contains(item) bool*
        +size() size_t*
        +isEmpty() bool*
        +clear() void*
    }

    class searchable_bag {
        <<abstract>>
        +search(item) T**
        +search(item) const T**
    }

    class array_bag {
        +add(item) bool
        +remove(item) bool
        +contains(item) bool
        +size() size_t
        +isEmpty() bool
        +clear() void
        -items_ T*
        -item_count_ size_t
    }

    class tree_bag {
        +add(item) bool
        +remove(item) bool
        +contains(item) bool
        +size() size_t
        +isEmpty() bool
        +clear() void
        -root_ Node*
        -item_count_ size_t
    }

    class searchable_array_bag {
        <<falta — tú la implementas>>
        +search(item) T*
    }

    class searchable_tree_bag {
        <<falta — tú la implementas>>
        +search(item) T*
    }

    class set {
        <<falta — tú la implementas>>
        +insert(item) bool
        +erase(item) bool
        +contains(item) bool
        +find(item) T*
        +size() size_t
        +empty() bool
        +clear() void
    }

    bag <|-- searchable_bag : virtual
    bag <|-- array_bag : virtual
    bag <|-- tree_bag : virtual

    searchable_array_bag ..> array_bag : falta heredar
    searchable_array_bag ..> searchable_bag : falta heredar
    searchable_tree_bag ..> tree_bag : falta heredar
    searchable_tree_bag ..> searchable_bag : falta heredar
    set ..> searchable_bag : falta envolver
```

**Lectura rápida:**

| Símbolo | Significado |
|---------|-------------|
| `<<abstract>>` | Clase con métodos `= 0` — no se instancia |
| `<<falta>>` | Lo que debes escribir tú |
| Línea sólida `--\|>` | Herencia (is-a) |
| Línea punteada `..>` | Relación pendiente / composición |

**Estado inicial:** `array_bag` y `tree_bag` funcionan solos (permiten duplicados), pero **no tienen `search()`**. `searchable_bag` define `search()` pero **no tiene implementación concreta**. No existe `set`.

---

### DESPUÉS — jerarquía completa tras tu implementación

```mermaid
classDiagram
    direction TB

    class bag {
        <<abstract>>
        +add() +remove() +contains()
        +size() +isEmpty() +clear()
    }

    class searchable_bag {
        <<abstract>>
        +search(item) T*
        +search(item) const T*
    }

    class array_bag {
        <<concreto>>
        array dinámico
        duplicados OK
    }

    class tree_bag {
        <<concreto>>
        BST
        duplicados OK
    }

    class searchable_array_bag {
        <<concreto — original/>>
        +search() lineal O(n)
        hereda add/remove de array_bag
    }

    class searchable_tree_bag {
        <<concreto — original/>>
        +search() en BST O(log n)
        hereda add/remove de tree_bag
    }

    class set {
        <<concreto — original/>>
        -bag_ searchable_bag*
        +insert() rechaza duplicados
        +erase() +find() +contains()
    }

    bag <|-- searchable_bag : virtual
    bag <|-- array_bag : virtual
    bag <|-- tree_bag : virtual

    array_bag <|-- searchable_array_bag
    searchable_bag <|-- searchable_array_bag

    tree_bag <|-- searchable_tree_bag
    searchable_bag <|-- searchable_tree_bag

    set o-- searchable_bag : bag_ puntero polimórfico
    set ..> searchable_array_bag : puede apuntar a
    set ..> searchable_tree_bag : puede apuntar a
```

---

### Problema del diamante (por qué `virtual`)

Sin `virtual`, `searchable_array_bag` heredaría **dos copias** de `bag`. Con `virtual`, solo hay **una**.

```mermaid
graph TD
    subgraph antes["Sin virtual — ERROR"]
        B1[bag]
        AB1[array_bag]
        SB1[searchable_bag]
        SAB1[searchable_array_bag]
        B1 --> AB1
        B1 --> SB1
        AB1 --> SAB1
        SB1 --> SAB1
    end

    subgraph despues["Con virtual — CORRECTO"]
        B2[bag virtual]
        AB2[array_bag]
        SB2[searchable_bag]
        SAB2[searchable_array_bag]
        B2 --> AB2
        B2 --> SB2
        AB2 --> SAB2
        SB2 --> SAB2
    end
```

**En el copy constructor siempre inicializa la base virtual:**

```cpp
searchable_array_bag(const searchable_array_bag& other)
    : bag<T>(),              // ← imprescindible
      array_bag<T>(other),
      searchable_bag<T>() {}
```

---

### Flujo de uso después de implementar

```mermaid
flowchart LR
    subgraph bags["Bags — permiten duplicados"]
        AB[array_bag]
        TB[tree_bag]
        SAB[searchable_array_bag]
        STB[searchable_tree_bag]
        AB --> SAB
        TB --> STB
    end

    subgraph set_layer["Set — NO duplicados"]
        S[set]
    end

    SAB -->|"new searchable_array_bag()"| S
    STB -->|"new searchable_tree_bag()"| S

    S -->|"insert(x)"| CHECK{search x?}
    CHECK -->|NULL| ADD[bag_->add]
    CHECK -->|existe| REJECT[return false]
```

**Ejemplo en código:**

```cpp
set<int> s(new searchable_array_bag<int>());
s.insert(10);  // search → NULL → add → true
s.insert(10);  // search → puntero → false (duplicado)
```

---

## Qué te dan / qué escribes tú

| Te dan | Tú implementas |
|--------|----------------|
| `bag.hpp` | — |
| `searchable_bag.hpp` | — |
| `array_bag.hpp`, `tree_bag.hpp` | — |
| — | `searchable_array_bag` |
| — | `searchable_tree_bag` |
| — | `set` |

## Orden en el examen (60–90 min)

```text
1. searchable_array_bag.hpp   (~20 min) — solo search() + OCF
2. searchable_tree_bag.hpp    (~20 min) — search() en BST + OCF
3. set.hpp                    (~15 min) — wrapper + insert
4. .cpp vacíos con #include   (~5 min)
5. Compilar con el main       (~10 min)
```

## Paso 1: searchable_array_bag

```cpp
class searchable_array_bag
    : public array_bag<T>, public searchable_bag<T>
{
    // OCF: inicializar bag<T>() en copia (herencia virtual)
    // search: bucle lineal con getItems() y size()
    // retornar &items[i] o NULL
};
```

## Paso 2: searchable_tree_bag

```cpp
class searchable_tree_bag
    : public tree_bag<T>, public searchable_bag<T>
{
    // find_node recursivo (igual que contains del tree_bag)
    // retornar &node->data o NULL
};
```

## Paso 3: set

```cpp
class set {
    searchable_bag<T>* bag_;
public:
    explicit set(searchable_bag<T>* bag);
    ~set() { delete bag_; }

    bool insert(const T& item) {
        if (bag_->search(item)) return false;
        return bag_->add(item);
    }
    // erase → remove, find → search, empty → isEmpty
};
```

## Bag vs Set

| | bag | set |
|---|-----|-----|
| Duplicados | Sí | No |
| Añadir | `add()` | `insert()` retorna false si existe |

## Errores típicos

- Olvidar `public virtual bag<T>` en las bases (diamante)
- No inicializar `bag<T>()` en el copy ctor de las searchable
- `search` devuelve copia en vez de puntero
- Olvidar versión const y no-const de `search`
- Hacer `delete` del bag fuera del set (el set es dueño)

## Compilar desde esta carpeta

```bash
cd exam_rank05/level-01/polyset/original
c++ -Wall -Wextra -std=c++98 ../main.cpp \
    searchable_array_bag.cpp searchable_tree_bg.cpp set.cpp -o polyset
./polyset
```
