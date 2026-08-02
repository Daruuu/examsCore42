#ifndef BSQ_H
#define BSQ_H

#include "errno.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_elements
{
	int		num_lines;
	char	empty;
	char	obstacle;
	char	full;
}	t_elements;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
}	t_map;

typedef struct s_square
{
	int	i;
	int	j;
	int	size;	//tamaño del cuadrado 5 x 5 o 2x2
}	t_square;

#endif
