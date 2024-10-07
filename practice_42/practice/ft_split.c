//
// Created by daruuu on 9/30/24.
//
/*
Assignment name  : ft_split
		Expected files   : ft_split.c
		Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
		a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
		lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}

char    **ft_split(char *str)
{
	int		i;
	int		start;
	int		end;
	int		k;
	int		wc;
	char	**result;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i ++;
	wc = 0;
	while (str[i] != '\0')
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i ++;
		if (str[i])
			wc ++;
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i ++;
	}
	result = (char **) malloc(sizeof(char *) * (wc + 1));
	if (!result)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i ++;
		start= i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i ++;
		end = i;
		if (i > start)
		{
			result[k] = (char *) malloc(sizeof(char) * (end - start) + 1);
			ft_strncpy(result[k++],&str[start], end - start);
		}
	}
	result[k] = NULL;
	return (result);
}

int main(int ac, char **av)
{
	char	**split;
	int 	i;

	if (ac == 2)
	{
		i = 0;
		split = ft_split(av[1]);
		while (split[i] != NULL)
		{
			printf("%s\n", split[i]);
			i ++;
		}
	}
	write(1, "\n", 1);
}