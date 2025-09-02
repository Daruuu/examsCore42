#include <unistd.h>

void	rottt(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = (str[i] - 'a' + 13) % 26 + 'a';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = (str[i] - 'A' + 13) % 26 + 'a';
		write(1, &str[i], 1);
		i ++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rottt(av[1]);
	write(1, "\n", 1);
	return (0);
}
