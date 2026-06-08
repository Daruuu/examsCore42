# vect2 — guía para el examen

## Orden de escritura (45–60 min)

```text
Paso 1  OCF + []           → compila, imprime v(1,2)
Paso 2  + - += -= -unario  → v2 += v3
Paso 3  * (vector y escalar) + *= + friend 3*v
Paso 4  ++ --              → v4++ imprime valor viejo
Paso 5  == != y <<         → main completo
```

---

## Qué hace cada operador (chuleta)

| Operador | Qué hace | Ejemplo |
|----------|----------|---------|
| `vect2()` | Crea (0, 0) | `vect2 v1;` |
| `vect2(x,y)` | Crea (x, y) | `vect2 v2(1, 2);` |
| `vect2(const&)` | Copia | `const vect2 v3(v2);` |
| `operator=` | Asignación | `v4 = v2;` |
| `[0]` / `[1]` | Accede a x / y | `v[1] = 12;` |
| `+` | Suma componentes | `(1,2)+(3,4)=(4,6)` |
| `+=` | Suma in-place | `v2 += v3` |
| `-` | Resta componentes | `(5,5)-(2,3)=(3,2)` |
| `-=` | Resta in-place | `v1 -= v2` |
| `-v` | Negación | `-(9,18)=(-9,-18)` |
| `v * w` | **Elemento a elemento** | `(2,3)*(4,5)=(8,15)` |
| `v * n` | **Escalar** | `(3,6)*3=(9,18)` |
| `n * v` | Escalar (friend) | `3 * v2` |
| `*=` | Escalar in-place | `v1 *= 42` |
| `++v` | x++, y++, devuelve nuevo | `++v4` → imprime (3,4) |
| `v++` | Devuelve viejo, luego ++ | `v4++` → imprime (1,2) |
| `--v` / `v--` | Igual que ++ pero -1 | |
| `==` | x igual y x, y igual y | |
| `!=` | Negación de == | delega en `!(*this == o)` |
| `<<` | Imprime `{x, y}` | con espacio tras la coma |

---

## Truco: dos `operator*`

C++ elige según el tipo derecho:

```cpp
v3 + v3 * 2;   // 2 es int  → escalar → (2,4), luego +(1,2) → (3,6)
v * w;         // w es vect2 → elemento a elemento
```

---

## Delegación (menos código)

Solo implementa la lógica en unos pocos; el resto delega:

```cpp
bool operator!=(const vect2& o) const { return !(*this == o); }

vect2 operator++(int) { vect2 old(*this); ++*this; return old; }
vect2 operator--(int) { vect2 old(*this); --*this; return old; }

friend vect2 operator*(int s, const vect2& v) { return v * s; }
```

---

## Seguir el main línea a línea

| Código | Resultado |
|--------|-----------|
| `v2 += v3` | (2, 4) |
| `v1 -= v2` | (-2, -4) |
| `v2 = v3 + v3 * 2` | (3, 6) |
| `v2 = 3 * v2` | (9, 18) |
| `v2 += v2 += v3` | (20, 40) |
| `v1 *= 42` | (-84, -168) |
| `v1 = v1 - v1 + v1` | (-84, -168) |
| `v4++` imprime | {1, 2} |
| `++v4` imprime | {3, 4} |

---

## Errores típicos

- Olvidar `friend` para `3 * v`
- Solo un `operator*` (falta escalar o vector)
- `++` solo incrementa x (debe ser x **e** y)
- `<<` sin espacio: `{1,2}` ≠ `{1, 2}`
- Olvidar `const` en `[]`, `==`, `<<`

---

## Compilar

```bash
c++ -Wall -Wextra -Werror -std=c++98 vect2.cpp main.cpp -o vect2
./vect2
```
