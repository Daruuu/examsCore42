#include "bsq_exam.h"

/**
 * Versión "Examen Final": Optimizada, corta y con todas las validaciones críticas.
 */

void	free_map(t_map map)
{
	for (int i = 0; i < map.height; i++)
		free(map.map[i]);
	free(map.map);
}

int fill_elements(FILE *file, t_elements *elements)
{
    char	*line;
    size_t	len;
    ssize_t	ret;
    int		i;

    /* Versión fscanf (falla si empty es espacio: salta whitespace antes de %c)
     *
     * int ret = fscanf(file, "%d %c %c %c",
     *     &elements->lines, &elements->empty, &elements->obstacle, &elements->full);
     * if (ret < 4 || elements->lines <= 0)
     *     return (1);
     */

    line = NULL;
    len = 0;
    ret = getline(&line, &len, file);
    if (ret <= 0)
    {
        free(line);
        return (1);
    }
    i = 0;
    while (line[i] == ' ' || line[i] == '\t')
        i++;
    elements->lines = 0;
    while (line[i] >= '0' && line[i] <= '9')
        elements->lines = elements->lines * 10 + line[i++] - '0';
    if (elements->lines <= 0)
        return (free(line), 1);
    if (line[i] == ' ' || line[i] == '\t')
        i++;
    elements->empty = line[i++];
    if (line[i] == ' ' || line[i] == '\t')
        i++;
    elements->obstacle = line[i++];
    if (line[i] == ' ' || line[i] == '\t')
        i++;
    elements->full = line[i];
    free(line);

    fprintf(stderr, "DEBUG fill_elements: lines=%d empty='%c'(%d) obstacle='%c'(%d) full='%c'(%d)\n",
        elements->lines,
        elements->empty, (unsigned char)elements->empty,
        elements->obstacle, (unsigned char)elements->obstacle,
        elements->full, (unsigned char)elements->full);

    /* 2. Validar que los caracteres sean diferentes */
    if (elements->empty == elements->obstacle || elements->empty == elements->full || elements->obstacle == elements->full)
        return 1;

    /* 3. Validar que los caracteres sean imprimibles (' ' a '~') */
    if (elements->empty < ' ' || elements->empty > '~')
        return 1;
    if (elements->obstacle < ' ' || elements->obstacle > '~')
        return 1;
    if (elements->full < ' ' || elements->full > '~')
        return 1;

    return 0;
}

int fill_map(FILE* file, t_elements elements, t_map* map)
{
    size_t len = 0;
    char* line = NULL;

    map->height = elements.lines;
    map->width = 0;
    map->map = malloc(sizeof(char*) * map->height);
    if (!map->map)
        return 1;
    for (int i = 0; i < map->height; i++)
        map->map[i] = NULL;

    /* Con fscanf, consumir el '\n' que deja en el buffer:
     *
     * if (getline(&line, &len, file) == -1)
     * {
     *     free(line);
     *     free_map(*map);
     *     return (1);
     * }
     */

    for (int i = 0; i < map->height; i++)
    {
        ssize_t ret = getline(&line, &len, file);
        /* 3. Validar si el archivo termina antes de tiempo */
        if (ret <= 0)
        {
             free(line);
             free_map(*map);
             return 1;
        }
        if (line[ret - 1] == '\n')
        {
            ret--;
        }
        /* Versión estricta (2): exigir '\n' al final de cada línea.
         * Descomentar y quitar el bloque de arriba si la moulinette lo pide:
         *
         * if (line[ret - 1] != '\n')
         * {
         *     free(line);
         *     free_map(*map);
         *     return 1;
         * }
         * ret--;
         */

        /* 4. Validar ancho de línea constante (y >= 1) */
        if (i == 0)
        {
            map->width = (int)ret;
            if (map->width < 1)
            {
                free(line);
                free_map(*map);
                return 1;
            }
        }
        else if ((int)ret != map->width)
        {
            free(line);
            free_map(*map);
            return 1;
         }

        map->map[i] = malloc(map->width + 1);
        if (!map->map[i])
        {
            free(line);
            free_map(*map);
            return 1;
        }
        for (int j = 0; j < map->width; j++)
        {
            /* 5. Validar que solo haya caracteres permitidos */
            if (line[j] != elements.empty && line[j] != elements.obstacle)
            {
                free(line);
                 free_map(*map);
                 return 1;
            }
            map->map[i][j] = line[j];
        }
        map->map[i][map->width] = '\0';
    }
    /* Versión estricta (3): rechazar si hay más líneas que las declaradas.
     * Descomentar si la moulinette lo pide:
     *
     * if (getline(&line, &len, file) != -1)
     * {
     *     free(line);
     *     free_map(*map);
     *     return 1;
     * }
     */
    free(line);
    return 0;
}

int find_min(int n1, int n2, int n3)
{
    int min = n1;
    if (n2 < min) min = n2;
    if (n3 < min) min = n3;
    return min;
}

void find_square(t_elements elements, t_map map, t_square* square)
{
    int **matrix = malloc(sizeof(int*) * map.height);
    for (int i = 0; i < map.height; i++)
        matrix[i] = malloc(sizeof(int) * map.width);

    for (int i = 0; i < map.height; i++)
    {
        for (int j = 0; j < map.width; j++)
        {
            /* 6. Lógica DP con else if para no sobrescribir obstáculos */
            if (map.map[i][j] == elements.obstacle)
                matrix[i][j] = 0;
            else if (i == 0 || j == 0)
                matrix[i][j] = 1;
            else
                matrix[i][j] = find_min(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]) + 1;

            /* 7. Guardar el primer máximo (más arriba y a la izquierda) */
            if (matrix[i][j] > square->size)
            {
                square->size = matrix[i][j];
                square->i = i - square->size + 1;
                square->j = j - square->size + 1;
            }
        }
    }

    for (int i = 0; i < map.height; i++)
        free(matrix[i]);
    free(matrix);
}

void print_square(t_elements elements, t_map map, t_square square)
{
    for (int i = square.i; i < square.size + square.i; i++)
        for (int j = square.j; j < square.size + square.j; j++)
            map.map[i][j] = elements.full;

    for (int i = 0; i < map.height; i++)
    	
        fprintf(stdout, "%s\n", map.map[i]);
}

int execute_bsq(FILE* file)
{
    t_elements elements;
    t_map map;
    t_square square = {0, 0, 0};

    if (fill_elements(file, &elements)) return 1;
    if (fill_map(file, elements, &map)) return 1;

    find_square(elements, map, &square);
    print_square(elements, map, square);
    free_map(map);

    return 0;
}

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        if (execute_bsq(stdin))
            fprintf(stdout, "Error: invalid map\n");
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            FILE *file = fopen(argv[i], "r");
            if (!file)
                fprintf(stdout, "Error: cannot open file\n");
            else
            {
                if (execute_bsq(file))
                    fprintf(stdout, "Error: invalid map\n");
                fclose(file);
            }
            /* 8. Salto de línea entre mapas (solo si no es el último) */
            if (i < argc - 1)
                fprintf(stdout, "\n");
        }
    }
    return 0;
}