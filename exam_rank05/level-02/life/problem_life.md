### Entendiendo el Problema de Life (Game of Life)

Para practicar este problema de examen, es fundamental dividirlo en tres fases claras. El reto no es solo el algoritmo del "Juego de la Vida" en sí, sino cómo gestionar la entrada de datos (el "bolígrafo") y el estado del tablero.

---

#### 1. Estructura y Preparación
Lo primero es definir cómo vas a guardar la información. Una estructura (`struct`) te ayudará a mantener el código organizado.

*   **El Tablero:** Usa una matriz de caracteres (ej. `char board[1000][1000]`).
*   **El Estado:** Necesitas guardar el ancho, el alto, el número de iteraciones, la posición actual del bolígrafo (`row`, `col`) y si está dibujando o no (`drawing`).

#### 2. Flujo de Implementación sugerido
Te recomiendo practicar siguiendo este orden exacto:

1.  **Parsing de Argumentos:** Lee `width`, `height` e `iterations` usando `atoi`.
2.  **El Sistema del Bolígrafo (Entrada Estándar):**
    *   Empieza en `(0, 0)`.
    *   Usa un bucle `while (read(0, &c, 1) > 0)` para leer los comandos `w, a, s, d, x`.
    *   **Punto clave:** Si `drawing` es activo, marca la celda actual como `'O'`. Decide si marcas al moverte o al pulsar `x`. (Según el `subject.txt`, el bolígrafo viaja libremente y marcas si está bajado).
3.  **El Algoritmo de Life (Las Reglas):**
    *   Necesitas una función `count_neighbors(row, col)` que mire las 8 celdas de alrededor. **Importante:** Verifica siempre que no te sales de los límites de la matriz.
    *   **Doble Buffer:** No puedes actualizar el tablero directamente mientras cuentas. Debes crear un tablero temporal, calcular el nuevo estado de todas las celdas basándote en el antiguo, y luego copiar el temporal al original.
4.  **Salida:** Un simple bucle anidado que imprima el tablero con `putchar` o `write`.

#### 3. Dónde poner el foco al practicar
Para el examen de 42, los errores más comunes suelen estar en:
*   **Límites:** El bolígrafo puede salirse de las dimensiones del tablero (no debe crashear, simplemente no dibuja si está fuera).
*   **Reglas exactas:**
    *   VIVA + (2 o 3 vecinos) = SIGUE VIVA.
    *   MUERTA + (3 vecinos) = NACE.
    *   Cualquier otro caso = MUERE/SIGUE MUERTA.
*   **Memoria:** Si el enunciado te permite `MAX_SIZE 1000`, una matriz estática es más segura y rápida de implementar que `malloc`.

#### 4. Ejemplo de Partida
Puedes usar el código que ya tienes en `exam_rank05/level-02/life/original/life.c` como referencia. Es una implementación sólida que separa la lógica de conteo, la de actualización (`play`) y la de lectura de comandos.

**Consejo final:** Practica escribirlo desde cero sin mirar la referencia, centrándote primero en que el bolígrafo "dibuje" bien el tablero inicial (usa 0 iteraciones para probarlo). Una vez que el dibujo sea idéntico al del ejemplo, añade la lógica de las iteraciones.