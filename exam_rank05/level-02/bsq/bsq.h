#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>

typedef struct s_map
{
	char	**grid;
	int		rows;
	int		cols;
	char	empty;
	char	obs;
	char	full;
}	t_map;

int		solve_bsq(t_map *map);
int		read_map(FILE *fp, t_map *map);
void	free_map(t_map *map);
void	print_map(t_map *map);

#endif
