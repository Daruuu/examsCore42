#include <unistd.h>

void	search(char *str, char search, char replace)
{
	int	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == search)
			str[i] = replace;
		write (1, &str[i], 1);
		i ++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 4 && !av[2][1] && !av[3][1])
	{
		search(av[1], av[2][0], av[3][0]);
	}
	write(1, "\n", 1);
	return (0);
}
