#include "bsq.h" 
/*
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
*/
int	fill_elements(FILE *file, t_elements *elements)
{
	char	*line = NULL;
	size_t	len = 0;
	ssize_t	bytes_read;
	int	i;

	bytes_read = getline(&line, &len, file);
	if (bytes_read <= 0)
	{
		free(line);
		return 1;
	}

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;

	elements->lines = 0;
	while (line[i] >= '0' && line[i] <= '9')
	{
		elements->lines = elements->lines * 10 + line[i++] - '0'; 
	}
	//	FILL NUM LINES
	if (elements->lines <= 0)
	{
		free(line);
		return 1;
	}

	//	FILL EMPTY char 
	if (line[i] == ' ' || line[i] == '\t')
		i++;
	elements->empty = line[i++];

	//	FILL obstacle char 
	if (line[i] == ' ' || line[i] == '\t')
		i++;
	elements->obstacle = line[i++];

	//	FILL full char 
	if (line[i] == ' '|| line[i] == '\t')
		i++;
	elements->full = line[i];

	free(line);

	if (elements->empty == elements->obstacle ||
		elements->empty == elements->full || 
		elements->obstacle == elements->full)
	{
		return 1;
	}
	if (elements->empty < ' ' || elements->empty > '~') 
		return 1;
	if (elements->obstacle < ' ' || elements->obstacle) 
		return 1;
	if (elements->full < ' ' || elements->full > '~')
		return 1;

	return 0;
}

int	fill_map(FILE *file, t_elements elements, t_map *map)
{
}

void	find_square(t_elements elements, t_map map, t_square *square)
{
}
void	print_map(t_elements elements, t_map map, t_square square)
{
	for(int i = square.i; i < square.size + square.i; i++)
	{
		for(int j = square.j; j < square.size + square.j; j++)
		{
			map.map[i][j] = elements.full;
		}
	}
	for (int i = 0; i < map.height; i++)
	{
		fprintf(stdout, "%s\n", map.map[i]);
	}
}

void	free_map(t_map map)
{
	for(int i = 0; i < map.height; i++)
	{
		free(map.map[i]);
	}
	free(map.map);
}

static int	find_min(int n1, int n2, int n3)
{
	int	min = n1;
	if (n2 < min)
		min = n2;
	if (n3 < min)
		min = n3;
	return min;
}

int	execute_bsq(FILE  *file)
{
	t_elements	elements;
	t_map		map;
	t_square	square = {0, 0, 0};

	if (fill_elements(file, &elements))
		return 1;
	if (fill_map(file, elements, &map))
		return 1;

	find_square(elements, map, &square);
	print_map(elements, map, square);
	free_map(map);

	return 0;
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		if (execute_bsq(stdin))
		{
			fprintf(stderr, "map error\n");
		}
	}
	else
	{
		for (int i = 1; i < ac; i++)
		{
			FILE *file = fopen(av[i], "r");
			if (!file)
			{
				fprintf(stderr, "map error\n");
			}
			else
			{
				if (execute_bsq(file))
				{
					fprintf(stderr, "map error\n");
				}
				fclose(file);
			}
			if (i < ac -1)
			{
				fprintf(stdout, "\n");
			}
		}
	}
	return 0;
}

