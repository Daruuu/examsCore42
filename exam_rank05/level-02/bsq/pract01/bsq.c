#include "bsq.h"

void	free_map(t_map *map)
{
	if (map->grid)
	{
		for (int i = 0; i < map->rows; i++)
			free(map->grid[i]);
	}
	free(map->grid);
}

int **allocate_matrix(int rows, int colums)
{
	int **matrix = calloc(rows, sizeof(int *));
	if (!matrix)
		return  NULL;

	for (int i = 0; i < rows; i++)
	{
		matrix[i]  = calloc(colums, sizeof(int));
		if (!matrix[i])
		{
			for (int j = 0; j < i; j++)
				free(matrix[j]);
			free(matrix);
			return NULL;
		}
	}
	return matrix;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int solve_bsq(t_map *map)
{

}
int	bsq_from_file(FILE *map_file)
{
	t_map map;

	map.grid = NULL;
	map.rows = 0;
	map.cols = 0;
	
	if (!validate_map(map_file, &map))
	{
		free_map(&map);
		return -1;
	}
	if (!solve_map(&map))
	{
		free_map(&map);
		return -1;
	}
	free_map(&map);

	return 1;
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		if (bsq_from_file(stdin) == -1)
			fputs("error map\n", stderr);
		return 0;
	}
	for (int i = 1; i < ac; i++)
	{
		if (bsq(av[i]) == -1)
		{
			fputs("error map\n", stderr);
		}
		if (ac > 2)
			fputs("\n", stdout);
	}
	return 0;
}
