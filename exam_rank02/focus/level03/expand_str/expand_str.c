#include <unistd.h>

void	expand_str(char *str)
{
	int i;
	i = 0;

	while (str[i] == ' ' || str[i] == '\t')
		i ++;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] != ' ' && str[i] != '\t'))
		{
			write(1, &str[i], 1);
			i ++;
		}
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i] != '\0')
			write(1, "   ", 3);
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		expand_str(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
