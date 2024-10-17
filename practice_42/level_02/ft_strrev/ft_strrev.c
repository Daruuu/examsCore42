/*
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);

*/
#include <stdlib.h>
#include <stdio.h>

char    *ft_strrev(char *str)
{
	int		i;
	char	tmp;
	int		len;

	len = 0;
	while (str[len] != '\0')
		len ++;
	i = 0;
	while (i < (len / 2))
	{
		tmp = str[i];
		str[i] = str[len - i];
		str[len - i] = tmp;
		i ++;
	}
	return (str);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char	*res = ft_strrev(av[1]);
		printf("%s\n", res);
	}
	return (0);
}
