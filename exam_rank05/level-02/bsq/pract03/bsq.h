#ifndef BSQ_H
#define BSQ_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_elements
{
	int	lines;
	char	empty;
	char	obstacle;
	char	full;
} t_elements;


typedef struct s_map
{
	char	**map;
	int height;
	int	width;
} t_map;


typedef struct s_square
{
	int size;
	int	i;
	int	j;
} t_square;

#endif
