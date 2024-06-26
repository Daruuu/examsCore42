#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	final;
	int	start;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i] != '\0')
			i++;
		i--;
		// encontrar el final del str
		// "hello world    \t"
		while (i >= 0 && (av[1][i] == ' ' || av[1][i] == '\t'))
			i--;
		final = i;
		// encontrar el comienzo del str
		while (i >= 0 && (av[1][i] != ' ' && av[1][i] != '\t'))
			i--;
		start = i + 1;
		while (start <= final)
		{
			write(1, &av[1][start], 1);
			start++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
/*
int	main(int ac, char **av)
{
	int	i;
	int	len;
	int	final;
	int	start;

	i = 0;
	len = 0;
	if (ac == 2)
	{
		while (av[1][i] != '\0')
			i++;
		i--;
		while (i-1 >= 0)
		{
			if (av[1][i] == ' ' || av[1][i] == '\t')
				i--;
			final = i;
			if (av[1][i] != ' ')
				i--;
			start = i;
		}
		while (start <= final)
		{
			write(1, &av[1][start], 1);
			start++;
		}
	}
	return (0);
}
*/
