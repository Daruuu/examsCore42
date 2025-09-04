Entender **qué papel juega cada función nueva** que implementamos y en qué orden debes abordarlas en el examen.

Te lo separo **paso a paso**:

---

## 1️⃣ `parse_factor`

```c
static node *parse_factor(char **s)
```

🔹 **Qué hace:**

* Se encarga de leer la unidad más básica de la gramática:

  * Un **número** (0–9).
  * Una **expresión entre paréntesis**: `( expr )`.

🔹 **Cómo lo hace:**

* Si el carácter actual es un dígito → crea un nodo `VAL` con ese número.
* Si es `'('` → llama recursivamente a `parse_expr_r` hasta encontrar el `')'`.
* Si no es nada de esto → error → `unexpected`.

🔹 **Por qué empezar aquí:**
👉 Porque es la base de todo. Sin `parse_factor`, no puedes reconocer números ni subexpresiones.

---

## 2️⃣ `parse_term`

```c
static node *parse_term(char **s)
```

🔹 **Qué hace:**

* Reconoce la **multiplicación**:
  `term → factor { '*' factor }`

🔹 **Cómo lo hace:**

1. Llama a `parse_factor` (obtiene un número o una subexpresión).
2. Mientras vea un `*`, construye un nodo `MULTI` con el nodo izquierdo y lo nuevo a la derecha.

Ejemplo:
`3*4*5` → se construye como:

```
     *
    / \
   *   5
  / \
 3   4
```

🔹 **Por qué después de factor:**
👉 Porque la multiplicación tiene mayor prioridad que la suma. Necesitas saber "qué es un factor" antes de encadenarlos con `*`.

---

## 3️⃣ `parse_expr_r`

```c
static node *parse_expr_r(char **s)
```

🔹 **Qué hace:**

* Reconoce la **suma**:
  `expr → term { '+' term }`

🔹 **Cómo lo hace:**

1. Llama a `parse_term` (porque una expresión es al menos un término).
2. Mientras vea un `+`, construye un nodo `ADD`.

Ejemplo:
`3+4*5` → se construye como:

```
    +
   / \
  3   *
     / \
    4   5
```

✅ Gracias a que `parse_term` ya sabe manejar `*`, la precedencia es correcta.

---

## 4️⃣ `parse_expr`

```c
node *parse_expr(char *s)
```

🔹 **Qué hace:**

* Es el **punto de entrada** del parser.
* Llama a `parse_expr_r` para procesar la cadena completa.
* Al final, verifica si queda algún carácter sobrante.

  * Si sobra → error `Unexpected token`.
  * Si falta (ejemplo `1+`) → error `Unexpected end of input`.

🔹 **Por qué al final:**
👉 Porque es el wrapper que controla toda la entrada y garantiza que se consumió bien.

---

## Orden recomendado para prepararte en el examen 📝

1. **Empieza por `parse_factor`**

   * Es lo más simple: reconocer un número o `(` expr `)`.

2. **Sigue con `parse_term`**

   * Encadena factores con `*`.

3. **Luego `parse_expr_r`**

   * Encadena términos con `+`.

4. **Finalmente `parse_expr`**

   * Integra todo y controla errores de entrada completa.

---

## Resumen visual del flujo:

```
parse_expr
   └── parse_expr_r   (maneja '+')
          └── parse_term   (maneja '*')
                 └── parse_factor   (maneja números y paréntesis)
```

---

👉 Te lo digo en plan examen: si en los 10 primeros minutos entiendes `parse_factor`, ya tienes el 50% hecho, porque `parse_term` y `parse_expr_r` son básicamente el **mismo patrón repetido** con `*` y `+`.

¿Quieres que te haga un ejemplo **trazado paso a paso** de cómo se parsea la cadena `"(3+4)*5"` con estas funciones, para que veas cómo se construye el AST?

