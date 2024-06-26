#include <unistd.h>

int	main(int ac, char **av)
{
	int	flag;
	if (ac == 2)
	{
		int	i = 0;
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		while (av[1][i] != '\0')
		{
			if (av[1][i] == ' ' || av[1][i] == '\t')
				flag = 1;
			if (flag)
				write(1, "   ", 3);
			flag = 0;
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
// "   hello"
