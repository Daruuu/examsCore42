#include <unistd.h>

void	last_word(char *str)
{
	int	i;
	int start;
	int end;

	i = 0;
	while (str[i])
		i ++;
	i --;
	while (i >= 0 && (str[i] == ' ' || str[i] == '\t'))
		i --;
	end = i;
	while (i >= 0 && str[i] != ' ' && str[i] != '\t')
		i --;
	i ++;
	start = i;
	while (start <= end)
	{
		write(1, &str[start], 1);
		start ++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		last_word(av[1]);
	}
	return (0);
}
