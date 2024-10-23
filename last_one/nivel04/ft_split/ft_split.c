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

char	*ft_strncpy(char *des, char *src, int len)
{
	int i = 0;
	while ((i < len) && src[i] != '\0')
	{
		des[i] = src[i];
		i ++;
	}
	des[i] = '\0';
	return (des);
}

char    **ft_split(char *str)
{
	int i;
	int start;
	int end;
	int k;
	int wc;
	char **split;

	i = 0;
	k = 0;
	wc = 0;

	while (str[i] != '\0')
	{
		while  (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i ++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i ++;
	}
	split = (char **) malloc(sizeof(char *) * wc + 1);
	if (!split)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		start = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		end = i;
		if (end > start)
		{
			split[k] = (char *) malloc(sizeof(char) * (end - start) + 1);
			ft_strncpy(split[k],&str[start], end - start);
			k++;
		}
	}
	split[k] = NULL;
	return (split);
}
