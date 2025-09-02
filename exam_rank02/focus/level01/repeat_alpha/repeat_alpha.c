#include <unistd.h>
#include <stdio.h>

void	repeat_alpha(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			count = str[i] - 'a' + 1;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			count = str[i] - 'A' + 1;
		else
			count = 1;
		while (count --)
			write(1, str[i], 1);
		i ++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		repeat_alpha(aav[1]);
	write(1, "\n", 1);
	return (0);
}
