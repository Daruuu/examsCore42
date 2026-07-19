#ifndef BSQ_H
#define BSQ_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>

typedef struct s_map
{
	char **map;
	int rows;
	int cols;
	char	empty;
	char	obstacle;
	char	full;
}	t_map;

#endif 
