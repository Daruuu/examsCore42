#include <stdlib.h>
#include <stdio.h>
/*
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);
*/
char	*ft_strdup(char *src)
{
	int i;
	char *dup;

	i = 0;
	while (src[i] != '\0')
		i ++;
	i ++;
	dup = malloc(sizeof(char) * i);
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i ++;
	}
	dup[i] = '\0';
	return (dup);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char	*result;
		result = ft_strdup(av[1]);
		printf("%s", result);
	}
	return (0);
}
