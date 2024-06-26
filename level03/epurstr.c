#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0;
	int	flag;

	if (ac == 2)
	{
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		while (av[1][i] != '\0')
		{
			if (av[1][i] == '\t' || av[1][i] == ' ')
				flag = 1;
			if (!(av[1][i] == '\t' || av[1][i] == ' '))
			{
				if (flag)
				write(1, " ", 1);
				flag = 0;
				write(1, &av[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
