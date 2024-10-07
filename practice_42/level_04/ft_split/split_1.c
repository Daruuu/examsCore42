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
#include <stdlib.h>
#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	if (!src || !dest)
		return (NULL);
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

//	"    hello in C language   "
char    **ft_split(char *str)
{
	int		i;
	int		start;
	int		end;
	int		k;
	char	**result;
	int 	wc;

	i = 0;
	wc = 0;
	while (str[i] != '\0')
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i ++;
		if (str[i])
			wc ++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i ++;
	}
	result = (char **) malloc(sizeof (char *) * (wc + 1));
	if (!result)
		return (NULL);
	i = 0;
	start = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i]  == '\t' || str[i] == '\n'))
			i ++;
		start = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i ++;
		end = i;
		if (start < end)
		{
			result[k] = (char *) malloc(sizeof(char) * (end - start) + 1);
			if (!result[k])
			{
				return (NULL);
			}
			ft_strncpy(result[k], &str[start], end - start);
			k ++;
		}
	}
	result[k] = NULL;
	return (result);
}

int main(int ac, char **av)
{
	char	**split;
	int 	i;

	i = 0;
	if ( ac == 2)
	{
		split = ft_split(av[1]);
		while (split[i] != NULL)
		{
			printf("%s\n", split[i]);
			i ++;
		}
	}
	free(split);

	return (0);
}