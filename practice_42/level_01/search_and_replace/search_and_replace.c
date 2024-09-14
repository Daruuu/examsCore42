#include <unistd.h>

void	search_and_repla(char *str, char search, char replace)
{
	int	i;

	i = 0;
	//if (search[1] != '\0' && replace[1] != '\0')
	//	write(1, "\n", 1);
	while (str[i] != '\0')
	{
		if (str[i] == search)
			str[i] = replace;
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 4 && !av[2][1] && !av[3][1])
		search_and_repla(av[1], av[2], av[3]);
	write(1, "\n", 1);
}
