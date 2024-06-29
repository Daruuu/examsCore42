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
		if (str[i] >= 'a' && str[i] <= 'z' && str[i] >)
			str[i] -= 32;
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

		}
	}
	return (0);
}
