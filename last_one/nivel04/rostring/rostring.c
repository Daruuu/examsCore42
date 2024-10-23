/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------
Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>*/
#include <stdlib.h>
#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, int len)
{
	int	i = 0;
	while (i < len && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str)
{
	int	i;
	int	k;
	int	wc;
	int	start;
	int	end;
	char	**split;

	i = 0;
	wc = 0;
	while (str[i] != '\0')
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	split = (char **) malloc(sizeof(char *) * (wc + 1));
	if (!split)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		while (str[i] && (str[i] == ' '  || str[i] == '\t' || str[i] == '\n'))
			i++;
		start = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		end = i;
		if (start < end)
		{
			split[k] = malloc(sizeof(char) * (end - start) + 1);
			if (!split[k])
				return (NULL);
			ft_strncpy(split[k], &str[start], end - start);
			k++;
		}
	}
	split[k] = NULL;
	return (split);
}
#include <unistd.h>

void	putstr(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i ++;
	}
}

int main (int ac, char **av)
{
	if (ac == 1)
		write(1, "\n", 1);
	else if (ac > 1)
	{
		int i;
		char **split = ft_split(av[1]);
		i = 1;
		while (split[i])
		{
			putstr(split[i]);
			if (split[i])
				write(1, " ", 1);
			i ++;
		}
		putstr(split[0]);
		write(1, "\n", 1);
	}
	return (0);
}