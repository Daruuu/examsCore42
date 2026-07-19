#include "bsq.h"

int	bsq_from_file(FILE *map_file)
{
	t_map mp;

	mp.map = NULL;
	mp.rows = 0;
	mp.cols = 0;
	
	if (!validate_map(map_file, &mp))
	{
		free_map(&mp);
		return -1;
	}
	if (!solve_map(&mp))
	{
		free_map(&mp);
		return -1;
	}
	free_map(&mp);

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
