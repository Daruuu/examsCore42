# alpha_mirror

## Descripción
Escribe un programa llamado `alpha_mirror` que tome una cadena y muestre esta cadena después de reemplazar cada carácter alfabético por el carácter alfabético opuesto, seguido de un salto de línea.

'a' se convierte en 'z', 'Z' se convierte en 'A', etc.

El caso se mantiene.

Si el número de argumentos no es 1, muestra solo un salto de línea.

## Ejemplo
```bash
$> ./alpha_mirror "abc"
zyx
$> ./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$> ./alpha_mirror | cat -e
$
```
