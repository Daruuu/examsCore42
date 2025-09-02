#include <unistd.h>

char *rev_print(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i ++;
	//i --;
	while (i >= 0 && str[i])
	{
		write(1, &str[i], 1);
		i --;
	}
	write(1, "\n", 1);
	return (str);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char	*resutl = rev_print(av[1]);
		int i = 0;
		while (resutl[i] != '\0')
		{
			write(1, &resutl[i], 1);
			i ++;
		}
	}
	return (0);
}
