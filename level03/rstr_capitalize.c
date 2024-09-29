#include <unistd.h>
/*
last character that is a letter of each word in uppercase and the rest
in lowercase,
*/

void	ft_rstr_capitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		if ((str[i] >= 'a' && str[i] <= 'z') &&
				(str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0'))
			str[i] -= 32;
		write(1, &str[i], 1);
		i++;

	}

}

int	main(int ac, char **av)
{
	int	i;
	if (ac < 2)
		write(1, "\n", 1);
	else
	{
		i = 0;
		while (i < ac - 1)
		{
			ft_rstr_capitalize(av[]);

		}
	}
	return (0);
}
