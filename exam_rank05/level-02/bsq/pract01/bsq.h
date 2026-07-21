#ifndef BSQ_H
#define BSQ_H

#include "errno.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_map
{
	char	**grid;
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
}	t_map;

#endif 
