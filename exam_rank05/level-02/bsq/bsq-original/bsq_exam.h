#ifndef BSQ_H
#define BSQ_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct s_elements
{
	int  lines;        // número de líneas del mapa
	char empty;        // '.'
	char obstacle;     // 'o'
	char full;         // 'x'
} t_elements;

typedef struct s_map
{
	char **map;        // matriz del mapa
	int width;         // ancho de cada línea
	int height;        // número de líneas
} t_map;

typedef struct s_square
{
	int i;      // fila inicio
	int j;      // columna inicio
	int size;   // tamaño del cuadrado
} t_square;

#endif