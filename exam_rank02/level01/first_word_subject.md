# first_word

## Descripción
Escribe un programa que tome una cadena y muestre la primera palabra de esa cadena, seguida de un salto de línea.

Una palabra es una sección de cadena delimitada por espacios o tabulaciones, o por el inicio/fin de la cadena.

Si el número de parámetros no es 1, o si no hay palabras, simplemente muestre un salto de línea.

## Ejemplo
```bash
$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
```
