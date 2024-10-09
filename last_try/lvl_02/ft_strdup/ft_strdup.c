/*
Assignment name  : ft_strdup
		Expected files   : ft_strdup.c
		Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);*/


#include <stdlib.h>
#include <stdio.h>

char    *ft_strdup(char *src)
{
	int	i = 0;
	char	*dup;
	while (src[i] != '\0')
		i ++;
	dup = (char *)malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i ++;
	}
	dup[i] = '\0';
	return (dup);
}
