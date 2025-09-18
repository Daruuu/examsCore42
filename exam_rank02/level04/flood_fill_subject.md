# flood_fill

## Descripción
Escribe una función que tome un char ** como un array bidimensional de char, un t_point como las dimensiones de este array y un t_point como el punto de partida.

A partir del t_point 'begin' dado, esta función llena una zona completa reemplazando los caracteres del interior con el carácter 'F'. Una zona es un grupo de caracteres iguales delimitados horizontal y verticalmente por otros caracteres o por el límite del array.

La función flood_fill no llenará en diagonal.

## Estructura
```c
typedef struct  s_point
{
    int           x;
    int           y;
}               t_point;
```

## Ejemplo
```bash
$> ./flood_fill
11111111
10001001
10010001
10110001
11100001

FFFFFFFF
F000F00F
F00F000F
F0FF000F
FFF0000F
```
