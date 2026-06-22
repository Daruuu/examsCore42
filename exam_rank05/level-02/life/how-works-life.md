---

## El problema: Game of Life

### ¿De qué va?

Tienes un tablero de `width × height` celdas. Un "bolígrafo" empieza en la esquina **top-left (0,0)** y recibes comandos por stdin para dibujarlo. Luego simulas N iteraciones del **Juego de la Vida** y imprimes el resultado.

### Parte 1 — El bolígrafo (leer comandos)

```
w → sube (row--)
s → baja (row++)
a → izquierda (col--)
d → derecha (col++)
x → toggle: levanta/baja el bolígrafo
```

**Clave**: el bolígrafo puede salir del tablero (moverse fuera), pero solo pinta cuando está **dentro** del tablero y está **bajado**.

```
echo 'sdxddssaaww' | ./life 5 5 0
```
Traza: baja → derecha → baja bolígrafo → derecha×2 → abajo×2 → izquierda×2 → arriba×2 → result: una 'C' o cuadrado

### Parte 2 — Reglas del Juego de la Vida

Cada celda mira sus **8 vecinos** y en la siguiente generación:

```
Celda VIVA  + 2 o 3 vecinos vivos → sigue VIVA
Celda VIVA  + otro nº             → MUERE
Celda MUERTA + exactamente 3      → NACE
```

> ⚠️ **Trampa clásica**: debes calcular el estado siguiente basándote en el estado ACTUAL — no actualices el tablero en el sitio. Necesitas un tablero auxiliar.

---

## Estructura mental para el examen

El problema tiene **4 bloques**, cada uno muy sencillo:

```
main()
 ├── 1. Leer args: width, height, iterations
 ├── 2. Init tablero a ' '
 ├── 3. Leer comandos (read) → mover bolígrafo → pintar 'O'
 ├── 4. loop N veces → play()
 └── 5. Imprimir tablero

play()
 ├── crear next_board[height][width]
 ├── para cada celda → count_alive() → aplicar reglas
 └── copiar next_board → board

count_alive()
 └── doble loop -1..+1 x -1..+1 (8 vecinos, skip 0,0)
```

---

## Lo que ya tienes vs lo que falta

El `life.c` que tienes **ya funciona** y está bien estructurado. El único detalle delicado es el comportamiento del bolígrafo al pintar con `x`:

- **`x` solo hace toggle** — pero si al bajar el bolígrafo ya estás en una celda válida, ¿pinta esa celda? Mirando el código actual: sí, pinta cuando `cmd == 'x'` también. Eso es lo correcto según los ejemplos del subject.

¿Quieres que te haga una versión **simplificada en un solo `.c`** sin `.h` separado, para tener todo visible a la vez durante el examen?