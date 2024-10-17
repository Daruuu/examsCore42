#include <unistd.h>

void	str_capi(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i ++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if ((i == 0 || str[i - 1] == ' ' || str[i - 1] == '\t') && \
			(str[i] >= 'a' && str[i] <= 'z'))
			str[i] = str[i] - 32;
		write(1, &str[i], 1);
		i ++;
	}
}

int main(int ac, char **av)
{
	if (ac == 1)
		write(1, "\n", 1);
	else
	{
		int i = 1;
		while (i < ac)
		{
			str_capi(av[i]);
			write(1, "\n", 1);
			i ++;
		}
	}
	return (0);
}
