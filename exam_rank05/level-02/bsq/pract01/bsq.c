#include "bsq.h"

void free_map(t_map map)
{
	for (int i = 0; i < map.height; i++)
	{
		free(map.map[i]);
	}
	free(map.map);
}

//	leemos 1ra linea y leemos: 9 . o x
int fill_elements(FILE* file, t_elements* elements)
{
	char* line = NULL;
	size_t len = 0;

	ssize_t bytes_read;
	int i;

	//===== 1)	LEER 1RA LINEA FICHERO
	bytes_read = getline(&line, &file, len);
	if (bytes_read <= 0)
	{
		free(line);
		return 1;
	}

	//====== 2)	SALTAMOS ESPACIOS - TABS INICIALES
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;

	//====== 3)	LEEMOS EL NUMERO DE FILAS DEL MAPA
	elements->num_lines = 0;
	while (line[i] >= '0' && line[i] <= '9')
	{
		elements->num_lines = elements->num_lines * 10 + (line[i++] - '0');
		// i++;
	}
	if (elements->num_lines <= 0)
	{
		free(line);
		return 1;
	}

	//====== 4)	LEER CARACTER QUE REPRESENTA "empty"
	if (line[i] == ' ' || line[i] == '\t')
		i++;
	elements->empty = line[i++];

	// ====== 5) LEER EL CARÁCTER QUE REPRESENTA "OBSTACLE"
	if (line[i] == ' ' || line[i] == '\t')
		i++;
	elements->obstacle = line[i++];

	// ======= 6) LEER EL CARÁCTER QUE REPRESENTA LA SOLUCIÓN ("FULL")
	if (line[i] == ' ' || line[i] == '\t')
		i++;
	elements->full = line[i++];

	free(line);

	// ===== 7) VALIDAR QUE LOS 3 CARACTERES SEAN DISTINTOS
	if (elements->empty == elements->obstacle ||
		elements->empty == elements->full ||
		elements->obstacle == elements->full)
	{
		return 1;
	}

	//	8) VALIDAR QUE LOS CARACTERES SEAN IMPRIMIBLES
	//	(' ' hasta '~' en ASCII)

	if (elements->empty < ' ' || elements->empty > '~')
		return 1;
	if (elements->obstacle < ' ' || elements->empty > '~')
		return 1;
	if (elements->full < ' ' || elements->empty > '~')
		return 1;


	return 0;
}

int fill_map(FILE* file, t_elements elements, t_map* map)
{
}

void find_square(t_elements elements, t_map map, t_square* square)
{
}

//	iterar por
void print_square(t_elements elements, t_map map, t_square square)
{
	for (int i = square.i; i < square.size + square.i; i++)
	{
		for (int j = square.j; j < square.size + square.j; j++)
		{
			map.map[i][j] = elements.full;
		}
	}
	for (int i = 0; i < map.height; i++)
	{
		fprintf(stdout, "%s\n", map.map[i]);
	}
}

int execute_bsq(FILE* file)
{
	t_elements elements;
	t_map map;
	t_square square = {0, 0, 0};

	if (fill_elements(file, &elements))
		return 1;
	if (fill_map(file, elements, &map))
		return 1;

	find_square(elements, map, &square);
	print_square(elements, map, square);
	free_map(map);

	return 0;
}

int main(int ac, char** av)
{
	if (ac == 1)
	{
		if (execute_bsq(stdin))
			fprintf(stderr, "map error\n");
	}
	else
	{
		for (int i = 1; i < ac; i++)
		{
			FILE* file = fopen(av[i], "r");
			if (!file)
				fprintf(stderr, "map error\n");
			else
			{
				if (execute_bsq(file))
					fprintf(stderr, "map error\n");
				fclose(file);
			}
			if (i < ac - 1)
			{
				fprintf(stdout, "\n");
			}
		}
	}
	return 0;
}
