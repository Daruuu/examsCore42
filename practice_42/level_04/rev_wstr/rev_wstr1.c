/*
Assignment name  : rev_wstr
		Expected files   : rev_wstr.c
		Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the
		begin/end of the string.

If the number of parameters is different from 1, the program will display
'\n'.

In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
		ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
		$> ./rev_wstr "Wingardium Leviosa" | cat -e
		Leviosa Wingardium$
		$> ./rev_wstr | cat -e
		$
$>
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, int size)
{
	int i;

	i = 0;
	while (i < size && src[i])
	{
		dest[i] = dest[i];
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str)
{
	int 	i;
	int 	start_word;
	int 	end_word;
	int 	wc;
	int 	k;
	char	**result;

	i = 0;
	wc = 0;
	while (str[i] != '\0')
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i ++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i ++;
	}
	result = (char **) malloc(sizeof(char *) * (wc + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i ++;
		start_word = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i ++;
		end_word = i;
		if (start_word < end_word)
		{
			result[k] = malloc(sizeof(char *) * (end_word - start_word) + 1;
			if (!result[k])
				return (NULL);
			ft_strncpy(result[k], &str[start_word], end_word - start_word );
			k ++;
		}
		result[k] = '\0';
	}
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i ++;
	return (i);
}

int	main(int ac, char **av)
{
	char	**split;
	int		i;
	int 	wc;

	if (ac == 2)
	{
		i = 0;
		wc = 0;
		split = ft_split(av[1]);
		//CONTAR PALABRAS EN SPLIT
		while (split[wc] != NULL)
			wc ++;
		i = wc - 1;
		while (i >= 0)
		{
			write(1, split[i], ft_strlen(split[i]));
			if (i > 0)
				write(1, " ", 1);
			i --;
		}
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}