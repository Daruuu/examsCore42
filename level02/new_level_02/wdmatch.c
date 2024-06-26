#include <unistd.h>

void	putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int ac, char **av)
{
	char	*s1 = av[1];
	char	*s2 = av[2];
	
	char	*p1 = s1;
	char	*p2 = s2;

	int	i = 0;
	int	j = 0;
	while (p2[i] && p1[i])
	{
		if (p1[i] == p2[i])
			i++;
	}

	return (0);
}

/*
int main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ac == 3)
	{
		while (av[1][i] != '\0')
		{
			while (av[2][j] != '\0')
			{
				if (av[1][i] == av[1][j])
				{
					i++;
					write(1, &av[1][i], 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
*/
