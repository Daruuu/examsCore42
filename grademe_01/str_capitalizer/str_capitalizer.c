#include  <unistd.h>

void	str(char *s1)
{
	int	i;

	i = 0;
	if (s1[i] >= 'a' && s1[i] <= 'z')
		s1[i] = s1[i] - 32;
	write(1, &s1[i], 1);
	i ++;
	while (s1[i] != '\0')
	{
		if (s1[i] >= 'A' && s1[i] <= 'Z')
			s1[i] += 32;
		if ((s1[i] >= 'a' && s1[i] <= 'z') && (s1[i - 1] == ' ' || s1[i - 1] == '\t'))
			s1[i] -= 32;
		write(1, &s1[i], 1);
		i ++;
	}
}

int	main(int ac, char **av)
{
	int	i;

	if (ac < 2)
	{
		write(1, "\n", 1);
	}
	i = 1;
	while (i < ac)
	{
		str(av[i]);
		write(1, "\n", 1);
		i ++;
	}
	return (0);
}
