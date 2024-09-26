#include <unistd.h>

void	repeat(char *s1)
{
	int	i;
	int	count;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] >= 'A' && s1[i] <= 'Z')
			count = s1[i] - 'A' + 1;
		else if (s1[i] >= 'a' && s1[i] <= 'z')
			count = s1[i] - 'a' + 1;
		else
			count = 1;
		while (count --)
			write(1, &s1[i], 1);
		i ++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		repeat(av[1]);
	}
	write (1, "\n", 1);
	return (0);
}
