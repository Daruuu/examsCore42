El problema implementa el Juego de la Vida de Conway.

### Primero dibujas el tablero mediante la entrada estándar:

* w: subir.
* s: bajar.
* a: izquierda.
* d: derecha.
* x: activar/desactivar el bolígrafo.
* El bolígrafo comienza en (0, 0) y levantado.

### Después simula las generaciones indicadas:
```bash
  ./life ancho alto iteraciones
```

### Qué hace cada parte

En **life.h**:

* t_game: guarda el tablero, sus dimensiones, iteraciones y estado del bolígrafo.
* width, height: tamaño del tablero.
* n: generaciones que se simularán.
* row, col: posición del bolígrafo.
* drawing: 0 no dibuja, 1 dibuja.
* board: matriz donde 'O' significa viva y ' ' muerta.

En **life.c**:

* count_alive(game, row, col): recorre las 8 posiciones alrededor de una celda y cuenta cuántas contienen 'O'. Ignora las posiciones fuera del tablero.
* play(game): calcula una generación completa:
    * Viva con 2 o 3 vecinos → sobrevive.
    * Muerta con exactamente 3 vecinos → nace.
    * Cualquier otro caso → queda muerta.

  Usa next_board para no modificar el tablero mientras todavía lo está calculando.
* main():
    1. Valida los 3 argumentos.
    2. Inicializa el tablero vacío.
    3. Lee los comandos con read.
    4. Mueve y activa/desactiva el bolígrafo.
    5. Ejecuta play() tantas veces como indique n.
    6. Imprime el resultado con putchar.

### Cómo practicarlo

Hazlo en este orden:

1. Crea la estructura y rellena el tablero con espacios.
2. Implementa solamente los movimientos y x.
3. Imprime el dibujo sin generaciones (iteraciones = 0).
4. Implementa count_alive.
5. Implementa una generación con un tablero auxiliar.
6. Añade el bucle de iteraciones.

Prueba clave, llamada “blinker”:

```bash
echo 'dxss' | ./life 3 3 0
echo 'dxss' | ./life 3 3 1
echo 'dxss' | ./life 3 3 2
```
Debe cambiar de línea vertical a horizontal y después volver a vertical.

--- 
