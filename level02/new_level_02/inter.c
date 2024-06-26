#include <unistd.h>

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	inter(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
				write(1, &s1[i], 1);
			j++;
		}
		i++;
		//write(1, &s1[i], 1);
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)	
	{
		inter(av[1], av[2]);
	}
	return (0);
}
