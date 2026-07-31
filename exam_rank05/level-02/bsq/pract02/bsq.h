#ifndef BSQ_H
#define BSQ_H

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

typedef	struct s_elements
{
	int		lines;
	char	empty;
	char	obstacle;
	char	full;
} t_elements;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
} t_map;

typedef struct s_square
{
	int	i;
	int	j;
	int	size;
} t_square;

#endif
